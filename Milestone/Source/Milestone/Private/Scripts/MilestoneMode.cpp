// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/MilestoneMode.h"
#include "Milestone/Milestone.h"
#include <Milestone/Public/Scripts/BPLib.h>
#include <Milestone/Public/Scripts/MilestoneStateOfGame.h>
AMilestoneMode::AMilestoneMode()
{
	//DefaultPawnClass = AMyDefaultPawn::StaticClass();
	GameStateClass = AMilestoneStateOfGame::StaticClass();
	//WARN("Game Start")
	PrimaryActorTick.bCanEverTick = true;
	FString msg = "Game Start";
	
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	TObjectPtr<AMilestoneStateOfGame> gs = GetGameState<AMilestoneStateOfGame>();
	//if (gs->HasMatchStarted())
	//{
	//	UBPLib::BlueprintWarn(msg);
	//}

}

void AMilestoneMode::BeginPlay()
{
	Super::BeginPlay();

}

void AMilestoneMode::HandleMatchHasStarted()
{
	UE_LOG(LogTemp, Warning, TEXT("Match started!"));
}

void AMilestoneMode::DoStuff()
{
	//AMyGameState* gs = GetGameState<AMyGameState *>();
}
void AMilestoneMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//float timeLeft = Time - GetWorld()->UWorld::GetTimeSeconds();
	////UE_LOG(LogTemp, Warning, TEXT("Time Left: %f"), timeLeft);

	//if (timeLeft <= 0)
	//{
	//	//Stop game
	//	FString msg = "Game Over: Time ran out";
	//	UBPLib::BlueprintWarn(msg);
	//}
	//else
	//{
	//	//FString t = ;
	//	FString msg = "Time Left : " + FString::SanitizeFloat(timeLeft);
	//	UBPLib::BlueprintWarn(msg);

	//}
	// ...
}