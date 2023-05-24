// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective.h"
#include "ObjectiveCollection.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROG2_API UObjectiveCollection : public UObjective
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<UObjective*> ObjectiveList;

public:

	// Denotes if the child objectives must be completed in a particular order
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	bool bOrderRequired;

	// Function call to activate the objective collection's objectives
	virtual void ActivateObjective() override;

	// Simple getter to determine if the objective has been completed
	virtual bool GetIsComplete() const override;


	// Function call to add a new objective to the objective collection
	UFUNCTION(BlueprintCallable)
	virtual void AddObjective(UObjective* ObjectiveToAdd);

	// Simple getter for objective list
	UFUNCTION(BlueprintPure)
	TArray<UObjective*> GetSubObjectiveList();

private:
	// Helper function to identify the next objective in the objective list that is incomplete
	UFUNCTION()
	UObjective* FindNextIncompleteObjective();

	// Helper function to activate the next objective in the objective list that is incomplete
	UFUNCTION()
	void ActivateNextIncompleteObjective();
};
