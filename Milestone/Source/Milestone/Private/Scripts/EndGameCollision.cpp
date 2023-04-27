// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/EndGameCollision.h"

// Sets default values for this component's properties
UEndGameCollision::UEndGameCollision()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));

	//// Set collider as the root
	//SetRootComponent(TriggerBox);

	//// Alternatively do this if it shouldn't be the root
	////TriggerBox->AttachToComponent(RootComponent);

	//// Set default size for box
	//TriggerBox->InitBoxExtent(FVector(100, 100, 100));
	//// Set box component to trigger
	//TriggerBox->SetCollisionProfileName(FName("Trigger"));
	//// Make sure the trigger
	//TriggerBox->SetGenerateOverlapEvents(true);
	// ...
}


// Called when the game starts
void UEndGameCollision::BeginPlay()
{
	Super::BeginPlay();
	//TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AExampleTriggerActor::OnBeginOverlap);
	//TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AExampleTriggerActor::OnEndOverlap);
	// ...
	
}


// Called every frame
void UEndGameCollision::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//void UEndGameCollision::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	UE_LOG(LogTemp, Warning, TEXT("Overlap!"));
//	if (Cast<ASandBoxCharacter>(OtherActor))
//	{
//		// Do something to the Player Character.
//		UE_LOG(LogTemp, Warning, TEXT("Player Overlap: %s"), *OtherActor->GetName());
//
//		// For example, get the camera following the player
//		ASandBoxCharacter* playerChar = Cast<ASandBoxCharacter>(OtherActor);
//		UE_LOG(LogTemp, Warning, TEXT("The camera following the player is: %s"), *playerChar->GetFollowCamera()->GetName());
//	}
//}
//void UEndGameCollision::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//	UE_LOG(LogTemp, Warning, TEXT("Player Exit!"));
//	if (Cast<ASandBoxCharacter>(OtherActor))
//	{
//		// Do something to the Player Character.
//		UE_LOG(LogTemp, Warning, TEXT("Player Exit: %s"), *OtherActor->GetName());
//	}
//}

