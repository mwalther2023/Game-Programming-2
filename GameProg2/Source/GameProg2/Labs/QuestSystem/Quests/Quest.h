// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Quest.generated.h"

UCLASS(Abstract, Blueprintable)
class GAMEPROG2_API AQuest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuest();

protected:
	// The first objective for the quest
	class UObjectiveCollection* RootObjectiveCollection;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Simple getter for RootObjectiveCollection
	UFUNCTION(BlueprintPure)
	virtual UObjectiveCollection* GetRootObjectiveCollection() const;

protected:
	// This function constructs the root objective collection and associates objectives with quests
	virtual UObjectiveCollection* SetupQuest();

	// Populate the objectives and sub objectives of the RootObjectiveCollection
	virtual void PopulateObjectives();
};
