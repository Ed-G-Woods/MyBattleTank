// Fill out your copyright notice in the Description page of Project Settings.

#include "MassWheelConstraint.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"

// Sets default values
AMassWheelConstraint::AMassWheelConstraint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("PhysicsConstraint"));
	SetRootComponent(PhysicsConstraint);

	Axle = CreateDefaultSubobject<USphereComponent>(FName("Axle"));
	Axle->SetupAttachment(RootComponent);

	AxleConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("AxleConstraint"));
	AxleConstraint->SetupAttachment(Axle);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Axle);

}

// Called when the game starts or when spawned
void AMassWheelConstraint::BeginPlay()
{
	Super::BeginPlay();

	SetupConstraint();

}

// Called every frame
void AMassWheelConstraint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMassWheelConstraint::SetupConstraint()
{
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	PhysicsConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Axle, NAME_None);

	AxleConstraint->SetConstrainedComponents(Axle, NAME_None, Wheel, NAME_None);
}

void AMassWheelConstraint::AddAxleForce(FVector Force)
{
	Axle->AddForce(Force);
}

