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

	
	UE_LOG(LogTemp, Warning, TEXT("%s"), *(FString::SanitizeFloat(DeltaTime)));
}
