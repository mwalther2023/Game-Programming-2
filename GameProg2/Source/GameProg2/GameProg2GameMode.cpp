// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameProg2GameMode.h"
#include "GameProg2Character.h"
#include "UObject/ConstructorHelpers.h"

AGameProg2GameMode::AGameProg2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
