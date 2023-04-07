// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lab03.generated.h"

UCLASS()
class GAMEPROG2_API ALab03 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALab03();
	UPROPERTY(EditAnywhere)
	float fooBar;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class ULab03ActorComponent> Lab03Component;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class ULab03ActorComponent> DynamicLab03Component;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class ULab03SceneComponent> SceneComponent;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UStaticMeshComponent> MyMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
