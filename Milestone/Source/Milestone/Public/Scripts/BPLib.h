// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPLib.generated.h"

/**
 * 
 */
UCLASS()
class MILESTONE_API UBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UPARAM(ref, DisplayName "msg")
		static void BlueprintLog(FString s);
	UPARAM(ref, DisplayName "msg")
		static void BlueprintWarn(FString s);

};
