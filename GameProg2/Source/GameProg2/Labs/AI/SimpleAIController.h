// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SimpleAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROG2_API ASimpleAIController : public AAIController
{
	GENERATED_BODY()
public:
	ASimpleAIController();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MoveSpeed = 100;
};
