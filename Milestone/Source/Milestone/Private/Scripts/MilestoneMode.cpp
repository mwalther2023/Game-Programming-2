// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/MilestoneMode.h"
#include "Milestone/Milestone.h"
#include <Milestone/Public/Scripts/BPLib.h>
#include <Milestone/Public/Scripts/MilestoneStateOfGame.h>
#include <Milestone/Public/Scripts/GamePlayerState.h>
#include <Milestone/Public/Scripts/PlayerCharacter.h>
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"

AMilestoneMode::AMilestoneMode()
{
	//DefaultPawnClass = AMyDefaultPawn::StaticClass();
	DefaultPawnClass = APlayerCharacter::StaticClass();
	GameStateClass = AMilestoneStateOfGame::StaticClass();
	PlayerStateClass = AGamePlayerState::StaticClass();
	//WARN("Game Start")
	PrimaryActorTick.bCanEverTick = true;
	
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//	
	//	control = PlayerPawnBPClass.Class.GetDefaultObject()->GetController();
	//}
	TObjectPtr<AMilestoneStateOfGame> gs = GetGameState<AMilestoneStateOfGame>();
	//playerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)); //Crashes game
}

void AMilestoneMode::BeginPlay()
{
	Super::BeginPlay();
	FString msg = "Gamemode BeginPlay: Game Has Started";
	UBPLib::BlueprintWarn(msg);
}
//void AMilestoneMode::HandleMatchHasEnded()
//{
//	FString msg = "GameMode | MatchEnd: Game Has Ended";
//	UBPLib::BlueprintWarn(msg);
//	PlayerStateClass.GetDefaultObject()->SetIsSpectator(true);
//	bool des = DefaultPawnClass.GetDefaultObject()->Destroy();
//}
//void AMilestoneMode::HandleMatchHasStarted()
//{
//	FString msg = "MatchBegin: Game Start";
//	UBPLib::BlueprintWarn(msg);
//	//RestartPlayer(control);
//	StartMatch();
//	StartPlay();
//}

void AMilestoneMode::DoStuff()
{
	//AMyGameState* gs = GetGameState<AMyGameState *>();
}
void AMilestoneMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TObjectPtr<AMilestoneStateOfGame> gs = GetGameState<AMilestoneStateOfGame>();
	
	if (gs->HasMatchEnded())
	{
		FString msg = "Gamemode Tick: Game Has Ended";
		UBPLib::BlueprintWarn(msg);
		//PlayerStateClass.GetDefaultObject()->SetIsSpectator(true);
		//APlayerController* PC = Cast<APlayerController>(DefaultPawnClass.GetDefaultObject()->GetController());
		//DefaultPawnClass.GetDefaultObject()->DisableInput(PC); //Doesnt work
		//bool des = DefaultPawnClass.GetDefaultObject()->Destroy();

		//if (APlayerController* PlayerController = Cast<APlayerController>(DefaultPawnClass.GetDefaultObject()->GetController()))
		//{
		//	/*if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		//	{
		//		// Subsystem->AddMappingContext(DefaultMappingContext, 0);
		//		Subsystem->RemoveMappingContext(DefaultPawnClass.GetDefaultObject()->Context) // Trying to get mapping context to remove and disable input
		//	}*/
		//	FString msg2 = "Gamemode Tick: DisableInput"; // Not being reached
		//	UBPLib::BlueprintWarn(msg2);
		//	//DefaultPawnClass.GetDefaultObject()->DisableInput(PlayerController);
		//	PlayerController->DisableInput(PlayerController);
		//}

		//APlayerController* PC = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
		//PC->DisableInput(PC);
		
		APlayerCharacter::GameEndInput();
		//playerCharacter->GameEndInput();
	}
}