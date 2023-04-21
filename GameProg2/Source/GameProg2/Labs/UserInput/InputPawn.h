// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputPawn.generated.h"

UCLASS()
class GAMEPROG2_API AInputPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AInputPawn();

	//Static Mesh Representation
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UStaticMeshComponent> StaticMesh;

	// UInputAction we want to map
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputAction> SlideCubeAction;

	// The base input mapping context we want to add
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TSoftObjectPtr<class UInputMappingContext> InputMapping;

	// Maximum speed to move
	UPROPERTY(EditAnywhere)
	float maxMoveSpeed;

	// Define a Move function
	virtual void Move(const struct FInputActionInstance& Instance);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector2D lastInput;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
