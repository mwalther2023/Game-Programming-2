// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointSceneComponent.h"
#include <GameProg2/Labs/BPLib.h>
//#include "BPLib.h"

// Sets default values for this component's properties
UWaypointSceneComponent::UWaypointSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWaypointSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	currentWaypoint = 0;
	start = list[currentWaypoint];
	end = list[currentWaypoint + 1];
	target = end;
	// ...
	
}


// Called every frame
void UWaypointSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	//Are we at the end waypoint?
	//UE_LOG(LogTemp, Warning, TEXT("Arrived? %s"), ((GetOwner()->GetActorLocation() == end) ? TEXT("true") : TEXT("false")));
	FVector direction = end - GetOwner()->GetActorLocation();
	float posDist = direction.Length();
	//UE_LOG(LogTemp, Warning, TEXT("posDist: %f"), posDist);
	if (posDist < 10.0)
	{
		//If so, update start and end to next waypoints
		currentWaypoint = (currentWaypoint + 1) % list.Num();
		int nextWaypoint = (currentWaypoint + 1) % list.Num();

		start = list[currentWaypoint];
		end = list[nextWaypoint];
	}
		
	target = UBPLib::MoveTowards(GetOwner()->GetActorLocation(), end, 200.0 * DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("CW: %d"), currentWaypoint);
	//UE_LOG(LogTemp, Warning, TEXT("LN: %d"), list.Num());
	//UE_LOG(LogTemp, Warning, TEXT("S: %f, %f, %f"), start.X, start.Y, start.Z);
	//UE_LOG(LogTemp, Warning, TEXT("E: %f, %f, %f"), end.X, end.Y, end.Z);
	//UE_LOG(LogTemp, Warning, TEXT("T: %s"), *target.ToString());

	GetOwner()->SetActorLocation(target);
	
	// ...
}

