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

	AimTowardsCrosshair();
	

}


////

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *(HitLocation.ToString()));
	}


}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OUT_HL) const
{
	OUT_HL = FVector(0, 0, 0);

	///Find CrosshairScreenLocation
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
// 	FVector2D CrosshairScreenLocation = FVector2D(ViewportSizeX * crosshairLocationX, ViewportSizeY * crosshairLocationY);
// 	UE_LOG(LogTemp, Warning, TEXT("%s"), *(CrosshairScreenLocation.ToString()));

	///DeprojectScreenPositionToWorld
	FVector DeprojectWorldLocation, DeprojectWorldDirection;
	DeprojectScreenPositionToWorld(ViewportSizeX * crosshairLocationX, ViewportSizeY * crosshairLocationY, DeprojectWorldLocation, DeprojectWorldDirection);
	UE_LOG(LogTemp, Warning, TEXT("%s , %s"), *(DeprojectWorldLocation.ToString()), *(DeprojectWorldDirection.ToString()));




	return false;
}
