// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

// Sets default values
AQuest::AQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//TODO: Implement
}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();
	//TODO: Implement
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

void AQuest::PopulateObjectives()
{
	UE_LOG(LogTemp, Error, TEXT("PopulateObjectives called for base class!"));
}

