// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Kismet/GameplayStatics.h"
#include "Milestone/Milestone.h"
#include "Components/AudioComponent.h"
// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 525.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	auto mesh = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny"));
	if (mesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(mesh.Object);
		GetMesh()->SetWorldLocation(FVector(0,0,-100));
		GetMesh()->SetWorldRotation(FQuat(FVector(0, 0, 1), (-90 * (3.14 / 180))));
	}
	auto anim = ConstructorHelpers::FObjectFinder<UAnimBlueprint>(TEXT("/Game/Characters/Mannequins/Animations/ABP_Manny.ABP_Manny"));
	if (anim.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(anim.Object->GeneratedClass);
	}
	auto action = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/ThirdPerson/Input/Actions/IA_Look.IA_Look"));
	if (action.Succeeded())
	{
		LookAction = action.Object;
	}
	auto j = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/ThirdPerson/Input/Actions/IA_Jump.IA_Jump"));
	if (j.Succeeded())
	{
		JumpAction = j.Object;
	}
	auto m = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/ThirdPerson/Input/Actions/IA_Move.IA_Move"));
	if (m.Succeeded())
	{
		MoveAction = m.Object;
	}
	auto input = ConstructorHelpers::FObjectFinder<UInputMappingContext>(TEXT("/Game/ThirdPerson/Input/IMC_Default.IMC_Default"));
	if (input.Succeeded())
	{
		DefaultMappingContext = input.Object;
	}
	//auto s = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/Labs/Lab8/IA_Sound.IA_Sound"));
	//if (s.Succeeded())
	//{
	//	SoundAction = action.Object;
	//}
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	BGAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("BG Audio"));
	auto bg = ConstructorHelpers::FObjectFinder<USoundBase>(TEXT("/Game/Level/Sounds/BG_Music.BG_Music"));
	if (bg.Succeeded())
	{
		BGAudioComponent->Sound = bg.Object;
	}
	auto aud = ConstructorHelpers::FObjectFinder<USoundBase>(TEXT("/Game/Level/Sounds/Walk.Walk"));
	if (aud.Succeeded())
	{
		AudioComponent->Sound = aud.Object;
	}
	Tags.Add(FName("Player"));
	//GetOwner()->Tags.Add(FName("Player"));
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	BGAudioComponent->Play();
	AudioComponent->Stop();
	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		//WARN("Binding Sound action");
		//EnhancedInputComponent->BindAction(SoundAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);

	}
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		AudioComponent->Play();
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}
void APlayerCharacter::GameEndInput()
{
	WARN("Character EndInput")
	//DisableInput(Cast<APlayerController>(Controller));
	APlayerController* PC = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GEngine->GameViewport->GetWorld(), 0));
	//PC->DisableInput(PC);
	PC->SetInputMode(FInputModeUIOnly());
}