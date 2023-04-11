// Fill out your copyright notice in the Description page of Project Settings.


#include "Lab03SceneComponent.h"

// Sets default values for this component's properties
ULab03SceneComponent::ULab03SceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULab03SceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULab03SceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	float theta = DeltaTime * speed;

	FRotator actorRot = GetOwner()->GetActorRotation();
	actorRot.Yaw = actorRot.Yaw + theta;
	GetOwner()->SetActorRotation(actorRot);
	if (int(actorRot.Yaw) % 360 == 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Full Roation"));
	}
	// ...
}

