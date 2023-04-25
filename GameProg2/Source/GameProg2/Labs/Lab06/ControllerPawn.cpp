// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerPawn.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "GameProg2/GameProg2.h"
#include "EnhancedInputSubsystems.h"
//#include "PawnMovementComponent.h"
//#include "CollidingPawnMovementComponent.h"

// Sets default values
AControllerPawn::AControllerPawn()
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

	auto action = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/Labs/Lab6/IA_Steering.IA_Steering"));
	if (action.Succeeded())
	{
		SteeringAction = action.Object;
	}
	auto m = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/Labs/Lab6/IA_Moving.IA_Moving"));
	if (m.Succeeded())
	{
		MovingAction = m.Object;
	}
	auto input = ConstructorHelpers::FObjectFinder<UInputMappingContext>(TEXT("/Game/Labs/Lab6/FlyMap.FlyMap"));
	if (input.Succeeded())
	{
		InputMapping = input.Object;
	}
}

// Called when the game starts or when spawned
void AControllerPawn::BeginPlay()
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
void AControllerPawn::Tick(float DeltaTime)
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
void AControllerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	WARN("Getting Enhanced Input Component");

	// Downcasting the PLayerInputComponent to be a UEnhancedInputComponent
	TObjectPtr<UEnhancedInputComponent> EIS = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	// Bind the Steering action
	WARN("Binding steer action");
	EIS->BindAction(SteeringAction, ETriggerEvent::Triggered, this, &AControllerPawn::Steer);
	// Bind the Steering action
	WARN("Binding move action");
	EIS->BindAction(MovingAction, ETriggerEvent::Triggered, this, &AControllerPawn::Move);

}
void AControllerPawn::Move(const struct FInputActionInstance& Instance)
{
	lastInput = Instance.GetValue().Get<FVector>();
	LOG("Move Input: (%f, %f)", lastInput.X, lastInput.Y);
	MoveBool = !MoveBool;

	// note, OurMovementComponent is a pointer to the movement component you created for this pawn,
	// also notice how we expect UpdatedComponent to point to our RootComponent for this code to execute!
	//if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
	//{
	//	OurMovementComponent->AddInputVector(GetActorForwardVector() * lastInput.X);
	//}


}
void AControllerPawn::Steer(const struct FInputActionInstance& Instance)
{
	lastInput = Instance.GetValue().Get<FVector>();
	LOG("Steer Input: (%f, %f, %f)", lastInput.X, lastInput.Y, lastInput.Z);
	FRotator rot = GetActorRotation();
	FVector forward = GetActorForwardVector();
	FQuat pawnQuat = GetActorQuat();

	if (lastInput.Y > 0 || lastInput.Y < 0)
	{
		FQuat pitchRotation = FQuat(GetActorRightVector(), lastInput.Y * (3.14/180));
		pawnQuat = pitchRotation * pawnQuat;
	}
	else if (lastInput.X > 0 || lastInput.X < 0)
	{
		FQuat yawRotation = FQuat(GetActorUpVector(), lastInput.X * (3.14 / 180));
		pawnQuat = yawRotation * pawnQuat;
	}
	else if (lastInput.Z > 0 || lastInput.Z < 0)
	{
		FQuat rollRotation = FQuat(GetActorForwardVector(), lastInput.Z * (3.14 / 180));
		pawnQuat = rollRotation * pawnQuat;
	}
	SetActorRotation(pawnQuat);
	//rot.Pitch -= lastInput.X;

	//// W is pressed
	//if (lastInput.X == 1)
	//{
	//	rot.Pitch -= 1;
	//}
	//// S is pressed
	//else if (lastInput.X == -1)
	//{
	//	rot.Pitch += 1;
	//}
	//// A is pressed
	//else if (lastInput.Y == -1)
	//{
	//	rot.Yaw -= 1;
	//}
	//// D is pressed
	//else if (lastInput.Y == 1)
	//{
	//	rot.Yaw += 1;
	//}
	//// E is Pressed
	//else if (lastInput.Z == 1)
	//{
	//	rot.Roll += 1;
	//}
	//// Q is Pressed
	//else if (lastInput.Z == -1)
	//{
	//	rot.Roll -= 1;
	//}
	
}
