// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsActor.h"
#include "GameProg2/GameProg2.h"
// Sets default values
APhysicsActor::APhysicsActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the base component and attach to root
	BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(BaseMeshComponent);

	// Assign our function to be the callback
	OnActorBeginOverlap.AddDynamic(this, &APhysicsActor::OnBeginOverlapBob);
	OnActorEndOverlap.AddDynamic(this, &APhysicsActor::OnEndOverlapBob);
}

// Called when the game starts or when spawned
void APhysicsActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysicsActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APhysicsActor::OnBeginOverlapBob(AActor* OverlappedActor, AActor* OtherActor)
{
	LOG("OnBeginOverlap Called!")

}

void APhysicsActor::OnEndOverlapBob(AActor* OverlappedActor, AActor* OtherActor)
{
	LOG("OnEndOverlap Called!")

}

void APhysicsActor::OnHitBob(AActor* HitActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	LOG("OnHit Called!")
}