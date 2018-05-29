// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

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

	UTankAimmingComponent* TankAimmingComponent = nullptr;

public:	
	// Called every frame

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void TankAimmingComponentSetup(UTankBarrel* BarrelToSet , UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable)
		void Fire();


	UPROPERTY(EditAnywhere)
		float LaunchSpeed = 100000.0;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectile> projectile;


	
};
