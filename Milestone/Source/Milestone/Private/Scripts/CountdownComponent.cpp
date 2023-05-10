// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/CountdownComponent.h"
#include "Milestone/Milestone.h"
#include <Milestone/Public/Scripts/BPLib.h>

// Sets default values for this component's properties
UCountdownComponent::UCountdownComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCountdownComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCountdownComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	float timeLeft = Time - GetWorld()->UWorld::GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("Time Left: %f"), timeLeft);
	
	if (timeLeft <= 0)
	{
		//Stop game
		FString msg = "Game Over: Time ran out";
		UBPLib::BlueprintWarn(msg);
	}
	else
	{
		//FString t = ;
		FString msg = "Time Left : " + FString::SanitizeFloat(timeLeft);
		UBPLib::BlueprintWarn(msg);

	}
	// ...
}

