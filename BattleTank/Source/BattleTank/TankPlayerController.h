// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetPawn(APawn* InPawn)override;


	UFUNCTION()
	void OnPossedTankDeath();

	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector& OUT_HL);

	////

	UPROPERTY(EditAnywhere, category = "i")
		float crosshairLocationX = 0.5;
	UPROPERTY(EditAnywhere, category = "i")
		float crosshairLocationY = 0.3;

	UPROPERTY(EditDefaultsOnly,category = "i")
		float AimRange = 1000000.0f;
	UPROPERTY(BlueprintReadOnly)
		FVector AimStartLocation;
	UPROPERTY(BlueprintReadOnly)
		FVector AimEndLocation;

	UPROPERTY(BlueprintReadOnly)
		ATank* PlayerTank = nullptr;

	bool isPlayerDie = false;

	FHitResult TankAimResult;

};
