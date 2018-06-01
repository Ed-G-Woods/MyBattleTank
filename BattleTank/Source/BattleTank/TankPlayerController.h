// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;
class UTankAimmingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	ATank * GetControlledTank() const;



	ATank* PlayerTank ;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	

	////

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OUT_HL);


	//

	UPROPERTY(EditAnywhere)
	float crosshairLocationX = 0.5;

	UPROPERTY(EditAnywhere)
	float crosshairLocationY = 0.3;

	UPROPERTY(BlueprintReadOnly)
	FVector AimStartLocation;

	UPROPERTY(BlueprintReadOnly)
	FVector AimEndLocation;

	FHitResult TankAimResult;

	UFUNCTION(BlueprintImplementableEvent,category = "Setup")
	void FoundUIAimingComponent(UTankAimmingComponent* AimComRef);

	
};
