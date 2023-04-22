// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/PlatformSpin.h"
#include "Engine/World.h"
// Sets default values for this component's properties
UPlatformSpin::UPlatformSpin()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlatformSpin::BeginPlay()
{
	Super::BeginPlay();
	start = GetOwner()->GetActorLocation();
	// ...
	
}


// Called every frame
void UPlatformSpin::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//FTransform transform = GetOwner()->GetActorTransform();
	//
	//FVector act = transform.GetLocation();
	//float t = GetWorld()->UWorld::GetTimeSeconds();
	//act.Y = sin(speed * t) * maxDist + start.Y + 100;

	//GetOwner()->SetActorLocation(act);

	FRotator rotation = GetOwner()->GetActorRotation();
	rotation.Yaw += DeltaTime * speed;
	GetOwner()->SetActorRotation(rotation);
	// ...
}

