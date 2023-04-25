// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectableActor.generated.h"

UCLASS()
class MILESTONE_API ACollectableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category = "Components")
		TObjectPtr<class UStaticMeshComponent> StaticMesh;
	UPROPERTY(EditAnywhere, Category = "Components") // This is necessary if you want to change collision settings in the editor
		class USphereComponent* TriggerBox;
	UPROPERTY(EditAnywhere, Category = "Components")
		UMaterial* StoredMaterial;
	UPROPERTY(EditAnywhere, Category = "Components")
		UMaterialInstanceDynamic* DynamicMaterialInst;

	// The functions to call on overlap start and end
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
