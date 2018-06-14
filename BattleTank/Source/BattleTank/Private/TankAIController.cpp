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
		MoveToActor(playerTank, AcceptanceRadius);


		aiTank->AimAt(playerTank->GetTargetLocation());


		if (aiTank->isAIAimmingLocked())
		{
			aiTank->Fire();
		}
	}

}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!PossessedTank) { UE_LOG(LogTemp, Warning, TEXT("Possessed Pawn not ATank,ATank->OnDie.AddUniqueDynamic failure")); return; }
		PossessedTank->OnDie.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
	}
}

void ATankAIController::OnPossedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Ai Destoryed!"));
	GetPawn()->DetachFromControllerPendingDestroy();
}

