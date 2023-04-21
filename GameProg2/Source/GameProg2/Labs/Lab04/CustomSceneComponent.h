// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomSceneComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPROG2_API UCustomSceneComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCustomSceneComponent();
	UFUNCTION(BlueprintCallable)
	void LocalTranslate(FVector move);
	UFUNCTION(BlueprintCallable)
	void LocalScale(FVector scale);
	UFUNCTION(BlueprintCallable)
	void LocalRotate(FVector axis, float theta);

	AActor* GetParent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere)
		AActor* parent;
	UPROPERTY(EditAnywhere)
		TArray<AActor*> children;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform LocalTransform;
		
};
