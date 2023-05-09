// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "GamePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MILESTONE_API AGamePlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	AGamePlayerState();
	UPROPERTY(EditAnywhere)
		bool alive = true;
	UPROPERTY(EditAnywhere)
		int32 lives = 5;
	void ReachedEnd();
};
