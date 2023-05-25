// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include "MyQuest.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROG2_API AMyQuest : public AQuest
{
	GENERATED_BODY()
	
public:
	AMyQuest();

private:
	// The trigger which fires when the destination is reached
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	class UBoxComponent* FirstDestinationTriggerBox;

	// The trigger which fires when the destination is reached
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	class USphereComponent* SecondDestinationTriggerSphere;

protected:
	// Initialize the root objective collection
	virtual UObjectiveCollection* SetupQuest() override;

	// Populates the Objectives and sub-objecives of the collection
	virtual void PopulateObjectives(UObjectiveCollection* RootObjCol) override;
};
