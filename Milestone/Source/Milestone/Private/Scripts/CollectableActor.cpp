// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/CollectableActor.h"
#include "Components/SphereComponent.h"
#include "Milestone/MilestoneCharacter.h"
// Sets default values
ACollectableActor::ACollectableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	TriggerBox = CreateDefaultSubobject<USphereComponent>(FName("TriggerSphere"));

	//Set collider as the root
	SetRootComponent(TriggerBox);

	// Alternatively do this if it shouldn't be the root
	//TriggerBox->AttachToComponent(RootComponent);

	// Set default size for box
	//TriggerBox->InitSphereExtent(FVector(100, 100, 100));
	TriggerBox->InitSphereRadius(80);
	// Set box component to trigger
	TriggerBox->SetCollisionProfileName(FName("Trigger"));
	// Make sure the trigger
	TriggerBox->SetGenerateOverlapEvents(true);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	/*SetRootComponent(StaticMesh);*/
	StaticMesh->AttachToComponent(TriggerBox, FAttachmentTransformRules::KeepRelativeTransform);

	auto mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (mesh.Succeeded())
	{
		StaticMesh->SetStaticMesh(mesh.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse"));
	if (FoundMaterial.Succeeded())
	{
		StoredMaterial = FoundMaterial.Object;
	}
	DynamicMaterialInst = UMaterialInstanceDynamic::Create(StoredMaterial, StaticMesh);

	StaticMesh->SetMaterial(0, DynamicMaterialInst);
}

// Called when the game starts or when spawned
void ACollectableActor::BeginPlay()
{
	Super::BeginPlay();
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ACollectableActor::OnBeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ACollectableActor::OnEndOverlap);
}

// Called every frame
void ACollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectableActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap!"));
	if (Cast<AMilestoneCharacter>(OtherActor))
	{
		// Do something to the Player Character.
		UE_LOG(LogTemp, Warning, TEXT("Player Overlap: %s"), *OtherActor->GetName());

		// For example, get the camera following the player
		AMilestoneCharacter* playerChar = Cast<AMilestoneCharacter>(OtherActor);
		//UE_LOG(LogTemp, Warning, TEXT("The camera following the player is: %s"), *playerChar->GetFollowCamera()->GetName());
	}
}

void ACollectableActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Player Exit!"));
	if (Cast<AMilestoneCharacter>(OtherActor))
	{
		// Do something to the Player Character.
		UE_LOG(LogTemp, Warning, TEXT("Player Exit: %s"), *OtherActor->GetName());
	}
}