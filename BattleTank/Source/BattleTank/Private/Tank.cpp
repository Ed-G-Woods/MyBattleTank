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

// Set 	TankAimmingComponent in Blueprint Constructiono


}
void ATank::BeginPlay()
{
	Super::BeginPlay();


}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimmingComponent)) { return; }

	TankAimmingComponent->AimAt(HitLocation);
}

void ATank::Fire()
{
	if (!ensure(TankAimmingComponent)) { return ; }

	TankAimmingComponent->Fire();
}

void ATank::FiringStateCheck()
{
	if (!ensure(TankAimmingComponent)) { return; }

	TankAimmingComponent->FiringStateCheck();
}

bool ATank::isAIAimmingLocked()const
{
	return TankAimmingComponent->B_isAIlocked();

}

