// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective.h"

const FText UObjective::GetObjectiveName()
{
	return ObjectiveName;
}

void UObjective::SetObjectiveName(FText newName)
{
	ObjectiveName = newName;
}

const bool UObjective::GetIsActive()
{
	return bIsActive;
}

void UObjective::ActivateObjective()
{
	UE_LOG(LogTemp, Warning, TEXT("Objective was activated: %s"), *ObjectiveName.ToString());

	// Set the active state
	bIsActive = true;

}

bool UObjective::GetIsComplete() const
{
	return true;
}

void UObjective::CompleteObjective() const
{
	// Execute the OnCompleted event
	OnCompleted.Broadcast();
}
