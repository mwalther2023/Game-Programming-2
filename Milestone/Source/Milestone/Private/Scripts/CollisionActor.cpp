// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/CollisionActor.h"
#include "Components/BoxComponent.h"
#include "Milestone/MilestoneCharacter.h"

// Sets default values
ACollisionActor::ACollisionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(FName("TriggerBox"));

	//Set collider as the root
	SetRootComponent(TriggerBox);

	// Alternatively do this if it shouldn't be the root
	//TriggerBox->AttachToComponent(RootComponent);

	// Set default size for box
	TriggerBox->InitBoxExtent(FVector(100, 100, 100));
	// Set box component to trigger
	TriggerBox->SetCollisionProfileName(FName("Trigger"));
	// Make sure the trigger
	TriggerBox->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ACollisionActor::BeginPlay()
{
	Super::BeginPlay();
	// Set up begin and end overlap events
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ACollisionActor::OnBeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ACollisionActor::OnEndOverlap);
}

// Called every frame
void ACollisionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollisionActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Overlap!"));
	UE_LOG(LogTemp, Warning, TEXT("Congrats you reached the end!"));
	if (Cast<AMilestoneCharacter>(OtherActor))
	{
		// Do something to the Player Character.
		UE_LOG(LogTemp, Warning, TEXT("Player Overlap: %s"), *OtherActor->GetName());
		GetWorld()->BeginPlay();
		// For example, get the camera following the player
		AMilestoneCharacter* playerChar = Cast<AMilestoneCharacter>(OtherActor);
		//UE_LOG(LogTemp, Warning, TEXT("The camera following the player is: %s"), *playerChar->GetFollowCamera()->GetName());
	}
}

void ACollisionActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Player Exit!"));
	if (Cast<AMilestoneCharacter>(OtherActor))
	{
		// Do something to the Player Character.
		UE_LOG(LogTemp, Warning, TEXT("Player Exit: %s"), *OtherActor->GetName());
	}
}