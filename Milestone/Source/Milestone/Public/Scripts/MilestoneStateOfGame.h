// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MilestoneStateOfGame.generated.h"

/**
 * 
 */
UCLASS()
class MILESTONE_API AMilestoneStateOfGame : public AGameState
{
	GENERATED_BODY()

public:
	AMilestoneStateOfGame();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Time = 60;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float MaxTime = 180;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float timeLeft = 60;
};
