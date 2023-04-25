// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ControllerPawn.generated.h"

UCLASS()
class GAMEPROG2_API AControllerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AControllerPawn();
	//Static Mesh Representation
	UPROPERTY(EditAnywhere)
		TObjectPtr<class UStaticMeshComponent> StaticMesh;

	// UInputAction we want to map
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		TObjectPtr<class UInputAction> MovingAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		TObjectPtr<class UInputAction> SteeringAction;

	// The base input mapping context we want to add
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		TSoftObjectPtr<class UInputMappingContext> InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		TObjectPtr<class UPawnMovementComponent> OurMovementComponent;
	// Maximum speed to move
	UPROPERTY(EditAnywhere)
		float maxMoveSpeed = 10;
	float moveSpeed = 1;
	// Define a Move function
	virtual void Move(const struct FInputActionInstance& Instance);
	virtual void Steer(const struct FInputActionInstance& Instance);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector lastInput;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool MoveBool = false;

};
