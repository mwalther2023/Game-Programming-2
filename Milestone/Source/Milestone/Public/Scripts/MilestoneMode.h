// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MilestoneMode.generated.h"

/**
 * 
 */
UCLASS()
class MILESTONE_API AMilestoneMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:	
	AMilestoneMode();

	void DoStuff();
};
