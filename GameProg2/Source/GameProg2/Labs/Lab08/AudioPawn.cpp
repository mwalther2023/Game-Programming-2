// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioPawn.h"
#include "Components/AudioComponent.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "GameProg2/GameProg2.h"
#include "EnhancedInputSubsystems.h"
// Sets default values
AAudioPawn::AAudioPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);

	auto mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/Labs/UserInput/MyCube.MyCube"));
	if (mesh.Succeeded())
	{
		StaticMesh->SetStaticMesh(mesh.Object);
	}

	auto action = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/Labs/Lab8/IA_Sound.IA_Sound"));
	if (action.Succeeded())
	{
		SoundAction = action.Object;
	}
	auto m = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/Labs/Lab6/IA_Moving.IA_Moving"));
	if (m.Succeeded())
	{
		MovingAction = m.Object;
	}
	auto input = ConstructorHelpers::FObjectFinder<UInputMappingContext>(TEXT("/Game/Labs/Lab8/Sound_Map.Sound_Map"));
	if (input.Succeeded())
	{
		InputMapping = input.Object;
	}
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	BGAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("BG Audio"));
	
	//auto audio = ConstructorHelpers::FObjectFinder<USoundBase>(TEXT("/Game/Labs/Lab8/Birds.Birds"));
	//if (audio.Succeeded())
	//{

	//		//action.Object;
	//}
}

// Called when the game starts or when spawned
void AAudioPawn::BeginPlay()
{
	Super::BeginPlay();
	
	BGAudioComponent->Play();
	AudioComponent->Stop();
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
void AAudioPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (MoveBool)
	{

		FVector loc = GetActorLocation();
		FVector forward = GetActorForwardVector();


		LOG("Moving Forward: %f", loc.X)
		if (moveSpeed < maxMoveSpeed)
		{
			forward *= moveSpeed;
			moveSpeed += 1;
		}
		else
		{
			forward *= maxMoveSpeed;
		}
		SetActorLocation(loc + forward * DeltaTime);
	}
	else
	{
		moveSpeed = 1;
	}
}

// Called to bind functionality to input
void AAudioPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	WARN("Getting Enhanced Input Component");

	// Downcasting the PLayerInputComponent to be a UEnhancedInputComponent
	TObjectPtr<UEnhancedInputComponent> EIS = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	// Bind the Sound action
	WARN("Binding Sound action");
	EIS->BindAction(SoundAction, ETriggerEvent::Triggered, this, &AAudioPawn::PlaySound);
	// Bind the Steering action
	WARN("Binding move action");
	EIS->BindAction(MovingAction, ETriggerEvent::Triggered, this, &AAudioPawn::Move);
}

void AAudioPawn::PlaySound(const struct FInputActionInstance& Instance)
{
	AudioComponent->Play();
}
void AAudioPawn::Move(const struct FInputActionInstance& Instance)
{
	lastInput = Instance.GetValue().Get<FVector>();
	LOG("Move Input: (%f, %f)", lastInput.X, lastInput.Y);
	MoveBool = !MoveBool;
}