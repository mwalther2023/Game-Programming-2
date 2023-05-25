// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjReachDestination.h"
#include "Components/ShapeComponent.h"
#include "GameProg2/GameProg2Character.h"
void UObjReachDestination::ActivateObjective()
{
	Super::ActivateObjective();

	// Begin Listening for an overlap event on the Destination Trigger
	Destination->OnComponentBeginOverlap.AddDynamic(this, &UObjReachDestination::ReachedDestination);
}

bool UObjReachDestination::GetIsComplete() const
{
	return bReachedDestination;
}

void UObjReachDestination::ReachedDestination(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// If we were overlapped by the player
	if (Cast<AGameProg2Character>(OtherActor)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Character Reached Destination %s"), *Destination->GetName());

		// Clearing all listeners from the delegate
		Destination->OnComponentBeginOverlap.Clear();

		// Indicate that the destination has been reached
		bReachedDestination = true;

		// Mark the Objective as complete
		CompleteObjective();
	}
}
