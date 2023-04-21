// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomSceneComponent.h"

// Sets default values for this component's properties
UCustomSceneComponent::UCustomSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCustomSceneComponent::BeginPlay()
{
	Super::BeginPlay();
	if (parent == NULL) 
	{
		LocalTransform = GetOwner()->GetTransform();
	}
	else
	{
		FTransform parentTransform = parent->GetActorTransform();
		LocalTransform = FTransform::Identity;
		FVector parLoc = parentTransform.GetLocation();
		LocalTransform.SetLocation(parLoc - GetOwner()->GetActorLocation());

	}
	
	// ...
	
}


// Called every frame
void UCustomSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (parent != NULL)
	{
		FTransform par = parent->GetActorTransform();
		//LocalTranslate(par.GetLocation());
		//LocalScale(par.GetScale3D());
		//LocalRotate(par.GetRotation().ToRotationVector(), par.GetRotation().GetAngle());

		// Multiply TRANSFORM by parent transform
		FTransform newTransform = LocalTransform * par;
		AActor* p = parent->GetParentActor();
		TArray<TObjectPtr<UCustomSceneComponent>> arr;
		while (p != NULL)
		{
			p->GetComponents<UCustomSceneComponent>(arr);
			newTransform = arr[0]->LocalTransform * newTransform;
			p = p->GetParentActor();

		}

		GetOwner()->SetActorTransform(newTransform);
		//LocalTransform = GetOwner()->GetActorTransform();
	}

	// ...
}
AActor* UCustomSceneComponent::GetParent()
{
	return parent;
}
void UCustomSceneComponent::LocalTranslate(FVector move)
{
	FVector loc = LocalTransform.GetLocation();
	GetOwner()->SetActorLocation(loc + move);
}
void UCustomSceneComponent::LocalScale(FVector scale)
{
	FVector s = LocalTransform.GetScale3D();
	//LocalTransform.SetScale3D(scale);
	GetOwner()->SetActorScale3D(scale * s);
}
void UCustomSceneComponent::LocalRotate(FVector axis, float theta)
{
	FQuat rotation = LocalTransform.GetRotation();
	FQuat rot = FQuat(axis, theta);
	//TArray<FVector> xRot = [(1,sin(theta),cos(theta)), (0, cos(theta), -sin(theta)), (0, 0, 1)];
	//TArray<FVector> yRot = [(sin(theta), 0, cos(theta)), (cos(theta), 1, -sin(theta)), (0, 0, 1)];
	//TArray<FVector> zRot = [(cos(theta), sin(theta), 0), (-sin(theta), cos(theta), 0), (0, 0, 1)];
	rotation = rotation * rot;
	//if (axis.X == 1)
	//{
	//	
	//}
	//if (axis.Y == 1)
	//{
	//	
	//}
	//if (axis.Z == 1)
	//{
	//	rotation.X = rotation.X * cos(theta) + rotation.Y * sin(theta);
	//	rotation.Y = rotation.X * (-sin(theta)) + rotation.Y * cos(theta);
	//}
	//LocalTransform.SetRotation(rotation);
	GetOwner()->SetActorRotation(rotation);
}