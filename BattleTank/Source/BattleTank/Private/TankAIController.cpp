// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	aiTank = Cast<ATank>(GetPawn());
	playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	if (playerTank)
	{
		MoveToActor(playerTank, 1000);


		aiTank->AimAt(playerTank->GetTargetLocation());


		aiTank->Fire();
	}

}

