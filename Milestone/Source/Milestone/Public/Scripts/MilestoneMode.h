// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MilestoneMode.generated.h"

/**
 * 
 */
UCLASS()
class MILESTONE_API AMilestoneMode : public AGameMode
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void HandleMatchHasStarted() override;
public:	
	AMilestoneMode();
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
		float Time = 30;
	void DoStuff();
};
