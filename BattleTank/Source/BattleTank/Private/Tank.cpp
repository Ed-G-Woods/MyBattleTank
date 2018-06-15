// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimmingComponent.h"
#include "TankMovementComponent.h"
#include "Engine/World.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}
void ATank::BeginPlay()
{
	Super::BeginPlay();

	TankHP = TankMaxHP;

	
}


//Function to TankAimmingComponent*

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimmingComponent) { UE_LOG(LogTemp, Warning, TEXT("Tank.cpp.30")); return; }

	TankAimmingComponent->AimAt(HitLocation);
}
void ATank::Fire()
{
	if (!TankAimmingComponent) { UE_LOG(LogTemp, Warning, TEXT("Tank.cpp.37")); return ; }
	
	TankAimmingComponent->Fire();
}
void ATank::FiringStateCheck()
{
	if (!TankAimmingComponent) { UE_LOG(LogTemp, Warning, TEXT("Tank.cpp.45")); return; }

	TankAimmingComponent->FiringStateCheck();
}
bool ATank::isAIAimmingLocked()const
{
	return TankAimmingComponent->B_isAIlocked();
}

//

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	TankHP -= DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("Damage: %f"), TankHP);
	if (TankHP <= 0)
	{
		OnDie.Broadcast();
	}
	
	return TankHP;
}

