// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Objective.generated.h"

// Event that should broadcast when the Objective is complete
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCompleted);

/**
 * 
 */
UCLASS(Abstract, Blueprintable) // Abstract - (No instance of this object can exist in level), Blueprintable - (Can be a base class for a blueprint)
class GAMEPROG2_API UObjective : public UObject
{
	GENERATED_BODY()

	// Denotes if the current objective is in progress
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	bool bIsActive;

	// The name of the task associated with the objective
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	FText ObjectiveName;

public:
	UPROPERTY(BlueprintAssignable, Category = "Objective Events")
	FOnCompleted OnCompleted;

	// Simple getter for the objective name
	UFUNCTION(Category = "Objective")
	const FText GetObjectiveName();

	// Simple setter for the objective name
	UFUNCTION(Category = "Objective")
	void SetObjectiveName(FText newName);

	// Simple getter for the objective state
	UFUNCTION(Category = "Objective")
	virtual const bool GetIsActive();

	// This is the function used to activate the objective
	UFUNCTION(Category = "Objective")
	virtual void ActivateObjective();

	// This is the function that is used to determine if the objective has been completed
	UFUNCTION(Category = "Objective")
	virtual bool GetIsComplete() const;


protected:

	// Function that is called when the objective is complete
	void CompleteObjective() const;



};
