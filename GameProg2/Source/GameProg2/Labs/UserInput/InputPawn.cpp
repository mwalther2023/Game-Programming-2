// Fill out your copyright notice in the Description page of Project Settings.


#include "InputPawn.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "GameProg2/GameProg2.h"
#include "EnhancedInputSubsystems.h"
// Sets default values
AInputPawn::AInputPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup Object to make the component
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);

	auto mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/Labs/UserInput/MyCube.MyCube"));
	if (mesh.Succeeded()) 
	{
		StaticMesh->SetStaticMesh(mesh.Object);
	}

	auto action = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/Labs/UserInput/IA_SlideCube.IA_SlideCube"));
	if (action.Succeeded())
	{
		SlideCubeAction = action.Object;
	}

	auto input = ConstructorHelpers::FObjectFinder<UInputMappingContext>(TEXT("/Game/Labs/UserInput/CubeMappingContext.CubeMappingContext"));
	if (input.Succeeded())
	{
		InputMapping = input.Object;
	}
}

// Called when the game starts or when spawned
void AInputPawn::BeginPlay()
{
	Super::BeginPlay();
	
	// Assign and Cast the controller to the player Controller
	if (TObjectPtr<APlayerController> PlayerController = Cast<APlayerController>(GetController()))
	{
		if (TObjectPtr<ULocalPlayer> localPlayer = Cast<ULocalPlayer>(PlayerController->GetLocalPlayer())) 
		{
			if (TObjectPtr<UEnhancedInputLocalPlayerSubsystem> inputSystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (!InputMapping.IsNull())
				{
					inputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 0);
				}
			}
		}
	}
}

// Called every frame
void AInputPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInputPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	WARN("Getting Enhanced Input Component");

	// Downcasting the PLayerInputComponent to be a UEnhancedInputComponent
	TObjectPtr<UEnhancedInputComponent> EIS = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	// Bind the move action
	WARN("Binding move actions");
	EIS->BindAction(SlideCubeAction, ETriggerEvent::Triggered, this, &AInputPawn::Move);

	
}
void AInputPawn::Move(const struct FInputActionInstance& Instance)
{
	lastInput = Instance.GetValue().Get<FVector2D>();
	LOG("Move Input: (%f, %f)", lastInput.X, lastInput.Y);
}

