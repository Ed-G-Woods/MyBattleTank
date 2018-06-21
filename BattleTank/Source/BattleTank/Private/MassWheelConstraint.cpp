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
	Axle->SetSimulatePhysics(true);

	AxleConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("AxleConstraint"));
	AxleConstraint->SetupAttachment(Axle);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Axle);
	Wheel->SetSimulatePhysics(true);	
	Wheel->SetNotifyRigidBodyCollision(true);

	

}

// Called when the game starts or when spawned
void AMassWheelConstraint::BeginPlay()
{
	Super::BeginPlay();

	Wheel->OnComponentHit.AddDynamic(this, &AMassWheelConstraint::OnCompHit);

	SetupConstraint();

}

// Called every frame
void AMassWheelConstraint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	isLanded = false;
	//UE_LOG(LogTemp, Warning, TEXT("OutHit"));
}

void AMassWheelConstraint::OnCompHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	isLanded = true;
	//UE_LOG(LogTemp, Warning, TEXT("OnHit"));
}


void AMassWheelConstraint::AddAxleForce(FVector Force)
{
	if (isLanded)
	{
		Axle->AddForce(Force);
		//UE_LOG(LogTemp, Warning, TEXT("isLanded"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("NotLanded"));
	}
}


void AMassWheelConstraint::SetupConstraint()
{
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	PhysicsConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Axle, NAME_None);

	AxleConstraint->SetConstrainedComponents(Axle, NAME_None, Wheel, NAME_None);
}