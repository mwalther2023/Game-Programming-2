// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/EnemyPawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
AEnemyPawn::AEnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(FName("Capsule"));
	CapsuleComp->InitCapsuleSize(42.f, 96.0f);
	SetRootComponent(CapsuleComp);
	StaticMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(RootComponent);
	auto mesh = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Quinn.SKM_Quinn"));
	if (mesh.Succeeded())
	{
		StaticMesh->SetSkeletalMesh(mesh.Object);
		StaticMesh->SetWorldLocation(FVector(0, 0, -90));
		StaticMesh->SetWorldRotation(FQuat(FVector(0, 0, 1), (-90 * (3.14 / 180))));
	}
	auto anim = ConstructorHelpers::FObjectFinder<UAnimBlueprint>(TEXT("/Game/Characters/Mannequins/Animations/ABP_Quinn.ABP_Quinn"));
	if (anim.Succeeded())
	{
		StaticMesh->SetAnimInstanceClass(anim.Object->GeneratedClass);
	}
	CharMove = CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("Move"));

}

// Called when the game starts or when spawned
void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

