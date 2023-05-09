// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class MILESTONE_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	AEnemyAIController();
private:
	bool direct = true;
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	int32 count;
	UPROPERTY(EditAnywhere, Category = "Components") // This is necessary if you want to change collision settings in the editor
		class UBoxComponent* TriggerBox;
	UPROPERTY(EditAnywhere)
		float MoveSpeed = 100;
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
