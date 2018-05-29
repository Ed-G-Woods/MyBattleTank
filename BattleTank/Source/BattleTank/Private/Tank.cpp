// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimmingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimmingComponent = CreateDefaultSubobject<UTankAimmingComponent>(FName("Aimming Component"));

}

void ATank::AimAt(FVector HitLocation)
{
	
	TankAimmingComponent->AimAt(HitLocation, LaunchSpeed);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::TankAimmingComponentSetup(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	TankAimmingComponent->Barrel = BarrelToSet;
	TankAimmingComponent->Turret = TurretToSet;
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("-----!FIRE!------"))
}

