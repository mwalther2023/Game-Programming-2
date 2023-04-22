// Copyright Epic Games, Inc. All Rights Reserved.

#include "MilestoneGameMode.h"
#include "MilestoneCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMilestoneGameMode::AMilestoneGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
