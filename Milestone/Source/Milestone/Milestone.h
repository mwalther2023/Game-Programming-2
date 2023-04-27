// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
// declare a log called LabsLog
DECLARE_LOG_CATEGORY_EXTERN(LabsLog, Log, All);

#define LOG(msg, ...) UE_LOG(LabsLog, Log, TEXT(msg), __VA_ARGS__)
#define WARN(msg, ...) UE_LOG(LabsLog, Warning, TEXT(msg), __VA_ARGS__)
#include "CoreMinimal.h"
