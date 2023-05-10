// Fill out your copyright notice in the Description page of Project Settings.


#include "SoundCollisionActor.h"
#include "GameProg2/GameProg2.h"
#include "Components/AudioComponent.h"
// Sets default values
ASoundCollisionActor::ASoundCollisionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(BaseMeshComponent);
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));

	// Assign our function to be the callback
	OnActorBeginOverlap.AddDynamic(this, &ASoundCollisionActor::OnBeginOverlapBob);
	OnActorEndOverlap.AddDynamic(this, &ASoundCollisionActor::OnEndOverlapBob);
}

// Called when the game starts or when spawned
void ASoundCollisionActor::BeginPlay()
{
	Super::BeginPlay();
	AudioComponent->Stop();

}

// Called every frame
void ASoundCollisionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASoundCollisionActor::OnBeginOverlapBob(AActor* OverlappedActor, AActor* OtherActor)
{
	LOG("OnBeginOverlap Called!")
	AudioComponent->Play();

}

void ASoundCollisionActor::OnEndOverlapBob(AActor* OverlappedActor, AActor* OtherActor)
{
	LOG("OnEndOverlap Called!")
	AudioComponent->Stop();
}

void ASoundCollisionActor::OnHitBob(AActor* HitActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	LOG("OnHit Called!")
}
