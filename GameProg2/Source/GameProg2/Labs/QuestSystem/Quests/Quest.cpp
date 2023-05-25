// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"
#include "../Objectives/ObjectiveCollection.h"
// Sets default values
AQuest::AQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();
	// Initialize the Root objective Collection and Populate it
	RootObjectiveCollection = SetupQuest();
	PopulateObjectives(RootObjectiveCollection);

	//Active root objective which starts teh quest
	RootObjectiveCollection->ActivateObjective();

}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UObjectiveCollection* AQuest::GetRootObjectiveCollection() const
{
	return RootObjectiveCollection;
}

UObjectiveCollection* AQuest::SetupQuest()
{
	UE_LOG(LogTemp, Error, TEXT("SetupQuest called for base class!"));
	return nullptr;
}

void AQuest::PopulateObjectives(UObjectiveCollection* RootObjCol)
{
	UE_LOG(LogTemp, Error, TEXT("PopulateObjectives called for base class!"));
}

