// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = GetControlledTank();

}

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

	PlayerTank->FiringStateCheck();
	
}


void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}


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
	
		AimEndLocation = AimStartLocation + (DeprojectWorldDirection * 1000000);

		if (GetWorld()->LineTraceSingleByChannel(
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

		}
	}



	return TankAimResult.IsValidBlockingHit();
}


