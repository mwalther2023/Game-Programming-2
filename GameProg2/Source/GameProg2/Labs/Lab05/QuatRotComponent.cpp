// Fill out your copyright notice in the Description page of Project Settings.


#include "QuatRotComponent.h"

// Sets default values for this component's properties
UQuatRotComponent::UQuatRotComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuatRotComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQuatRotComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FQuat actorRot = GetOwner()->GetActorQuat();
	FQuat rot = FQuat(RotationAxis, RotationSpeed * (3.14 / 180));
	GetOwner()->SetActorRotation(actorRot * rot);

	// ...
}

