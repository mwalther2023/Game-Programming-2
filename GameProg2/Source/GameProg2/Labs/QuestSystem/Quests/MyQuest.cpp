// Fill out your copyright notice in the Description page of Project Settings.


#include "MyQuest.h"
#include "../Objectives/ObjectiveCollection.h"
#include "../Objectives/ObjReachDestination.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"

AMyQuest::AMyQuest()
{
	// Created the trigger box
	FirstDestinationTriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("FirstDestinationTriggerBox"));
	FirstDestinationTriggerBox->SetupAttachment(RootComponent);
	FirstDestinationTriggerBox->InitBoxExtent(FVector(100,100,100));
	FirstDestinationTriggerBox->SetGenerateOverlapEvents(true);
	FirstDestinationTriggerBox->SetCollisionProfileName(TEXT("Trigger"), false);

	// Created the trigger box
	SecondDestinationTriggerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SecondDestinationTriggerSphere"));
	SecondDestinationTriggerSphere->SetupAttachment(RootComponent);
	//SecondDestinationTriggerSphere->InitBoxExtent(FVector(100, 100, 100));
	SecondDestinationTriggerSphere->InitSphereRadius(50);
	SecondDestinationTriggerSphere->SetGenerateOverlapEvents(true);
	SecondDestinationTriggerSphere->SetCollisionProfileName(TEXT("Trigger"), false);
}

UObjectiveCollection* AMyQuest::SetupQuest()
{
	// Create the RootObjectiveCollection
	UObjectiveCollection* RootObjectCol = NewObject<UObjectiveCollection>(this, UObjectiveCollection::StaticClass(), TEXT("Root Objective Collection"));
	RootObjectCol->bOrderRequired = true;
	RootObjectCol->SetObjectiveName(FText::FromString("A long way home"));


	// Return the created root objective collection
	return RootObjectCol;
}

void AMyQuest::PopulateObjectives(UObjectiveCollection* RootObjCol)
{
	// Create and set the data for the first Objective
	UObjReachDestination* ReachFirstDestinationObjective = NewObject<UObjReachDestination>(this, UObjReachDestination::StaticClass(), TEXT("Reach First Destination Objective"));
	ReachFirstDestinationObjective->SetObjectiveName(FText::FromString("Reach Town A"));
	ReachFirstDestinationObjective->Destination = FirstDestinationTriggerBox;
	// Added the objective to the RootObjectiveCollection
	RootObjectiveCollection->AddObjective(ReachFirstDestinationObjective);

	// Create and set the data for the first Objective
	UObjReachDestination* ReachSecondDestinationObjective = NewObject<UObjReachDestination>(this, UObjReachDestination::StaticClass(), TEXT("Reach Second Destination Objective"));
	ReachSecondDestinationObjective->SetObjectiveName(FText::FromString("Reach Town Z"));
	ReachSecondDestinationObjective->Destination = SecondDestinationTriggerSphere;
	// Added the objective to the RootObjectiveCollection
	RootObjectiveCollection->AddObjective(ReachSecondDestinationObjective);
}
