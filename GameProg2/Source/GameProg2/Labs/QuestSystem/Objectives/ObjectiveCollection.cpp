// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveCollection.h"

void UObjectiveCollection::ActivateObjective()
{
	Super::ActivateObjective();

	// If order is required
	if (bOrderRequired)
	{
		ActivateNextIncompleteObjective();
	}
	else // no order required
	{
		// Activate all sub objectives
		for (UObjective* Objective : ObjectiveList)
		{
			Objective->ActivateObjective();
		}
	}
}

bool UObjectiveCollection::GetIsComplete() const
{
	// Check all objectives
	for (UObjective* Objective : ObjectiveList)
	{
		// If even one objective is not complete
		if (!Objective->GetIsComplete())
		{
			// Not all objectives are complete
			return false;
		}
	}
	return true;
}

void UObjectiveCollection::AddObjective(UObjective* ObjectiveToAdd)
{
	ObjectiveList.Add(ObjectiveToAdd);
}

TArray<UObjective*> UObjectiveCollection::GetSubObjectiveList()
{
	return ObjectiveList;
}

UObjective* UObjectiveCollection::FindNextIncompleteObjective()
{
	// Check all objectives
	for (UObjective* Objective : ObjectiveList)
	{
		// If this objective is not compelete
		if (!Objective->GetIsComplete())
		{
			// This is the one
			return Objective;
		}
	}

	// There are no incomplete objectives so complete the objective collection
	CompleteObjective();
	return nullptr;
}

void UObjectiveCollection::ActivateNextIncompleteObjective()
{
	// Clear this objectives OnCompleted listeners
	OnCompleted.Clear();

	UObjective* NextIncompleteObjective = FindNextIncompleteObjective();
	// Make sure we got teh objective pointer
	if (IsValid(NextIncompleteObjective))
	{
		// Activate the next objective
		NextIncompleteObjective->ActivateObjective();

		// Delegate subscription to activate the next objective when this one is completed
		NextIncompleteObjective->OnCompleted.AddDynamic(this, &UObjectiveCollection::ActivateNextIncompleteObjective);
	}
}
