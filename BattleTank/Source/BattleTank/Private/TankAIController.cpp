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


	ATank* aiTank =  GetAIControllTank();

	if (aiTank)
	{

		UE_LOG(LogTemp, Warning, TEXT("%s 's AIController Begin Play"), *(aiTank->GetName()));
	}

	ATank* playerTank = GetPlayerTank();

	if (!playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("playertank Can't find"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("find playertank -- %s"),*(playerTank->GetName()));
	}

}

