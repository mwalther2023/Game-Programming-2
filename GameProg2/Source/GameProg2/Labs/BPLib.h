// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPLib.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROG2_API UBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static FVector MoveTowards(const FVector& startPos, const FVector& endPos, float maxDist);
	bool ToggleMovement(bool isMoving);
	
private:
	float fooVal;
};
