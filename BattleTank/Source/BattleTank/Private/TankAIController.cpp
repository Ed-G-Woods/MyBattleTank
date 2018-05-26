// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


ATank* ATankAIController::GetAIControllTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	aiTank =  GetAIControllTank();
	playerTank = GetPlayerTank();



}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	if (playerTank)
	{
		//move towards player

		//Aim at player

		aiTank->AimAt(playerTank->GetTargetLocation());

		//fire


	}

}

