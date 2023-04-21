// Fill out your copyright notice in the Description page of Project Settings.


#include "Lab03.h"
#include "Lab03ActorComponent.h"
#include "Lab03SceneComponent.h"
//#include "ConstructorHelpers.h"

// Sets default values
ALab03::ALab03()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Lab03Component = CreateDefaultSubobject<ULab03ActorComponent>(TEXT("Lab03Component"));

	SceneComponent = CreateDefaultSubobject<ULab03SceneComponent>(TEXT("Lab03SceneComponent"));
	SetRootComponent(SceneComponent);

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube Mesh"));
	/*SetRootComponent(MyMesh);*/
	MyMesh->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	if (mesh.Succeeded())
	{
		// this offsets it from the root       
		MyMesh->SetStaticMesh(mesh.Object);
		MyMesh->SetWorldScale3D(FVector(.50f));
	}
}

// Called when the game starts or when spawned
void ALab03::BeginPlay()
{
	Super::BeginPlay();
	DynamicLab03Component = NewObject<ULab03ActorComponent>(this, TEXT("Dynamic Lab03Component"));
	DynamicLab03Component->RegisterComponent();


}

// Called every frame
void ALab03::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

