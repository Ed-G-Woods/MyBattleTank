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
	if (!TankAimmingComponent) { return; }

	TankAimmingComponent->AimAt(HitLocation);
}


void ATank::Fire()
{
	if (!ensure(TankAimmingComponent)) { return ; }

	//UE_LOG(LogTemp, Warning, TEXT("-----!FIRE!------"))
	
	
	 bool isReloaded= GetWorld()->GetTimeSeconds()-LastFireTime > ReloadTime;

	if (isReloaded)
	{
		TankAimmingComponent->SpawnProjectileAndLaunch();

		LastFireTime = GetWorld()->GetTimeSeconds();
	}
	else
	{

	}


}

void ATank::FiringStateCheck()
{
	if (!ensure(TankAimmingComponent)) { return; }

	if (GetWorld()->GetTimeSeconds() - LastFireTime > ReloadTime)
	{
		if (TankAimmingComponent->islocked)
		{
			TankAimmingComponent->firingstatus = EFiringStatus::Locked;
			UE_LOG(LogTemp, Warning, TEXT("Locked"))
		}
		else
		{
			TankAimmingComponent->firingstatus = EFiringStatus::Aiming;
			UE_LOG(LogTemp, Warning, TEXT("Aiming"))
		}
	}
	else
	{
		TankAimmingComponent->firingstatus = EFiringStatus::Reloading;
		UE_LOG(LogTemp, Warning, TEXT("Reloading"))
	}

}

