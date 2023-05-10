// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AudioPawn.generated.h"

UCLASS()
class GAMEPROG2_API AAudioPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAudioPawn();
	UPROPERTY(EditAnywhere)
		TObjectPtr<class UStaticMeshComponent> StaticMesh;

	// UInputAction we want to map
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		TObjectPtr<class UInputAction> SoundAction;
	// The base input mapping context we want to add
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		TSoftObjectPtr<class UInputMappingContext> InputMapping;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		TObjectPtr<class UInputAction> MovingAction;
	virtual void PlaySound(const struct FInputActionInstance& Instance);
	virtual void Move(const struct FInputActionInstance& Instance);
	UPROPERTY(EditAnywhere)
		float maxMoveSpeed = 10;
	float moveSpeed = 1;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector lastInput;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TObjectPtr<class UAudioComponent> AudioComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TObjectPtr<class UAudioComponent> BGAudioComponent;
	bool MoveBool = false;

};
