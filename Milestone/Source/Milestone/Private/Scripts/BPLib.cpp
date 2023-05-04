// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/BPLib.h"
#include "Milestone/Milestone.h"

void UBPLib::BlueprintLog(FString s)
{
	LOG("%s",*s)
}

void UBPLib::BlueprintWarn(FString s)
{
	WARN("%s", *s)
}