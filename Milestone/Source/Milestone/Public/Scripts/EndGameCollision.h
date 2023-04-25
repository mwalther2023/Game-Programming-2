// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EndGameCollision.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MILESTONE_API UEndGameCollision : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEndGameCollision();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//UPROPERTY(EditAnywhere, Category = "Components") // This is necessary if you want to change collision settings in the editor
	//	class UBoxComponent* TriggerBox;

	//// The functions to call on overlap start and end
	//UFUNCTION()
	//	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//UFUNCTION()
	//	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
		
};
