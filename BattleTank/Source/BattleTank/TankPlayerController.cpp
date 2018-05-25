// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
	
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PlayerTank = GetControlledTank();

	if (PlayerTank)
	{

		UE_LOG(LogTemp, Warning, TEXT("%s 's PlayerController Begin Play"), *(PlayerTank->GetName()));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	

}


////

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(HitLocation.ToString()));
	}


}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OUT_HL) const
{
	OUT_HL = FVector(0, 0, 0);
	return false;
}
