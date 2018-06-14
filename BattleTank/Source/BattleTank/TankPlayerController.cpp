// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankPlayerController::BeginPlay()
{
	PlayerTank = Cast<ATank>(GetPawn());
	//Set PlayerTank before BeginPlay Blueprint
	Super::BeginPlay();
}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!isPlayerDie)
	{
		AimTowardsCrosshair();
		PlayerTank->FiringStateCheck();
	}
	else
	{
	//	UE_LOG(LogTemp, Warning, TEXT("Player Died!Spectating!"));
	}
}
void ATankPlayerController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!PossessedTank) { UE_LOG(LogTemp, Warning, TEXT("Possessed Pawn not ATank,ATank->OnDie.AddUniqueDynamic failure")); return; }
		PossessedTank->OnDie.AddUniqueDynamic(this, &ATankPlayerController::OnPossedTankDeath);
	}
}


////

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		PlayerTank->AimAt(HitLocation);
	}
}

void ATankPlayerController::OnPossedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("You Die!"));
	isPlayerDie = true;
	StartSpectatingOnly();
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OUT_HL)
{
	OUT_HL = FVector(0, 0, 0);

	///Find CrosshairScreenLocation
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	///DeprojectScreenPositionToWorld

	FVector DeprojectWorldDirection;

	if (DeprojectScreenPositionToWorld(ViewportSizeX * crosshairLocationX, ViewportSizeY * crosshairLocationY, AimStartLocation, DeprojectWorldDirection))
	{
		AimEndLocation = AimStartLocation + (DeprojectWorldDirection * AimRange);

		if (GetWorld()->LineTraceSingleByChannel
			(
			TankAimResult,
			AimStartLocation,
			AimEndLocation,
			ECC_Visibility
			
			)	
			)
		{
			OUT_HL = TankAimResult.Location;
		}
		else
		{
			OUT_HL = AimEndLocation;
		}
	}

	return true;
}


