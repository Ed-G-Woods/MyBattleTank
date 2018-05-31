// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankMovementComponent;
class UTankAimmingComponent;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	UTankAimmingComponent* TankAimmingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovement = nullptr;

public:	
	// Called every frame

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void Fire();


	UPROPERTY(EditDefaultsOnly)
		float LaunchSpeed = 10000.0;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> projectile;
	UPROPERTY(EditDefaultsOnly)
	float ReloadTime = 3;


	float LastFireTime = 0;
};
