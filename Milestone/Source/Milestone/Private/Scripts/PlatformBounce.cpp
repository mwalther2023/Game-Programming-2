// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/PlatformBounce.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UPlatformBounce::UPlatformBounce()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlatformBounce::BeginPlay()
{
	Super::BeginPlay();
	start = GetOwner()->GetActorLocation();
	// ...
	
}


// Called every frame
void UPlatformBounce::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FTransform transform = GetOwner()->GetActorTransform();
	FVector act = transform.GetLocation();
	//UWorld w;
	float t = GetWorld()->UWorld::GetTimeSeconds();
	act.Z = sin(speed * t) * maxDist + start.Z + 100;

	GetOwner()->SetActorLocation(act);
	// ...
}

