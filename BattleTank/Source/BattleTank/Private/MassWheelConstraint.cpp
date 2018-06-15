// Fill out your copyright notice in the Description page of Project Settings.

#include "MassWheelConstraint.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

// Sets default values
AMassWheelConstraint::AMassWheelConstraint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("PhysicsConstraint"));
	SetRootComponent(PhysicsConstraint);

	Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	Mass->SetupAttachment(RootComponent);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMassWheelConstraint::BeginPlay()
{
	Super::BeginPlay();

	auto parent = GetAttachParentActor();

	if (parent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Parent:-. %s"),*parent->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Parent Found"))
	}

		
	
}

// Called every frame
void AMassWheelConstraint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

