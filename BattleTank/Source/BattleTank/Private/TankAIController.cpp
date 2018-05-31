// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"



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
		//move towards player
		MoveToActor(playerTank, 300);


		//Aim at player

		aiTank->AimAt(playerTank->GetTargetLocation());

		//fire

		aiTank->Fire();
	}



}

