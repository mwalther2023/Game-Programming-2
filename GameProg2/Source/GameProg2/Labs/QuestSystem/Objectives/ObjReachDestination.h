// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective.h"
#include "ObjReachDestination.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROG2_API UObjReachDestination : public UObjective
{
	GENERATED_BODY()

	//Indicates if the destination has been reached
	UPROPERTY()
	bool bReachedDestination;

public:
	// The destination to reach
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UShapeComponent* Destination;


	// parent function overrides
	virtual void ActivateObjective() override;
	virtual bool GetIsComplete() const override;

private:

	UFUNCTION()
	void ReachedDestination(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
};
