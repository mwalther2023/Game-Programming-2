// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleAIController.h"
#include "GameProg2/GameProg2.h"

ASimpleAIController::ASimpleAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	//MoveSpeed = 100;
}

void ASimpleAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetPawn() == nullptr)
	{
		WARN("Simple AI Controller not possesing anything")
	}
}
void ASimpleAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	TObjectPtr<APawn> pawn = GetPawn<APawn>();
	if (pawn != nullptr)
	{
		pawn->AddMovementInput(pawn->GetActorForwardVector() * MoveSpeed * DeltaSeconds);
	}
	else
	{
		WARN("Simple AI Controller not connected to a pawn")
	}

}
