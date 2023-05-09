// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/EnemyAIController.h"
#include "Milestone/Milestone.h"
#include "Components/BoxComponent.h"
AEnemyAIController::AEnemyAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	//MoveSpeed = 100;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(FName("TriggerBox"));

	//Set collider as the root


	// Alternatively do this if it shouldn't be the root
	//TriggerBox->AttachToComponent(RootComponent);

	// Set default size for box
	TriggerBox->InitBoxExtent(FVector(100, 100, 100));
	// Set box component to trigger
	TriggerBox->SetCollisionProfileName(FName("Trigger"));
	// Make sure the trigger
	TriggerBox->SetGenerateOverlapEvents(true);
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetPawn() == nullptr)
	{
		WARN("Simple AI Controller not possesing anything")
	}
}
void AEnemyAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	TObjectPtr<APawn> pawn = GetPawn<APawn>();
	int32 t = 2;
	int32 time = GetWorld()->UWorld::GetRealTimeSeconds();
	
	
	if (pawn != nullptr)
	{
		if (time % t == 0 && time != count)
		{
			if (direct) 
			{
				pawn->SetActorRotation(FQuat(FVector(0, 0, 1), -180 * (3.14 / 180)));
				direct = !direct;
				WARN("Rotate -180")
			}
			else
			{
				pawn->SetActorRotation(FQuat(FVector(0, 0, 1), 360 * (3.14 / 180)));
				direct = !direct;
				WARN("Rotate 180")
			}
			
		}

		pawn->AddMovementInput(pawn->GetActorForwardVector() * MoveSpeed * DeltaSeconds);
		UE_LOG(LogTemp, Warning, TEXT("AiLog: Moving Forward"));
		count = GetWorld()->UWorld::GetRealTimeSeconds();
	}
	else
	{
		WARN("Simple AI Controller not connected to a pawn")
	}

}
void AEnemyAIController::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Overlap!"));
	UE_LOG(LogTemp, Warning, TEXT("AI Hit!"));
	//if (Cast<AMilestoneCharacter>(OtherActor))
	//{
	//	// Do something to the Player Character.
	//	UE_LOG(LogTemp, Warning, TEXT("Player Overlap: %s"), *OtherActor->GetName());
	//	GetWorld()->BeginPlay();
	//	// For example, get the camera following the player
	//	AMilestoneCharacter* playerChar = Cast<AMilestoneCharacter>(OtherActor);
	//	//UE_LOG(LogTemp, Warning, TEXT("The camera following the player is: %s"), *playerChar->GetFollowCamera()->GetName());
	//}
	TObjectPtr<APawn> pawn = GetPawn<APawn>();
	if (direct)
	{
		pawn->SetActorRotation(FQuat(FVector(0, 0, 1), 180 * (3.14 / 180)));
		direct = !direct;
		WARN("Rotate 180")
	}
	else
	{
		pawn->SetActorRotation(FQuat(FVector(0, 0, 1), -180 * (3.14 / 180)));
		direct = !direct;
		WARN("Rotate -180")
	}
}

void AEnemyAIController::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("AI Exit!"));
	//if (Cast<AMilestoneCharacter>(OtherActor))
	//{
	//	// Do something to the Player Character.
	//	UE_LOG(LogTemp, Warning, TEXT("Player Exit: %s"), *OtherActor->GetName());
	//}
}