// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/MilestoneStateOfGame.h"
#include <Milestone/Public/Scripts/BPLib.h>

AMilestoneStateOfGame::AMilestoneStateOfGame()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMilestoneStateOfGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float timeLeft = Time - GetWorld()->UWorld::GetTimeSeconds();

	if (timeLeft <= 0)
	{
		//Stop game
		FString msg = "Game Over: Time ran out";
		UBPLib::BlueprintWarn(msg);
		//HandleMatchHasEnded();
	}
	else
	{
		//FString t = ;
		FString msg = "Time Left : " + FString::SanitizeFloat(timeLeft);
		UBPLib::BlueprintWarn(msg);

	}
}