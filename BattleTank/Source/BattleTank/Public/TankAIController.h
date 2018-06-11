// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:


	virtual void BeginPlay() override;
	virtual void Tick(float Deltatime) override;

	virtual void SetPawn(APawn* InPawn) override;

	ATank* aiTank ;
	ATank* playerTank ;

	UPROPERTY(EditDefaultsOnly)
		float AcceptanceRadius = 7000;

	UFUNCTION()
		void OnPossedTankDeath();
	
};
