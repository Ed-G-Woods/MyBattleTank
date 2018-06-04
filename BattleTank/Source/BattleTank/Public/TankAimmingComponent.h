// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimmingComponent.generated.h"


UENUM()
enum class EFiringStatus : uint8
{
	Locked,
	Aiming,
	Reloading
};


class UTankBarrel;
class UTankTurret;
class AProjectile;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimmingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimmingComponent();

	void AimAt(FVector a);

	void MoveBarrelAndTurret(FVector AimDirection);

	void Fire();

	void SpawnProjectileAndLaunch();

	void FiringStateCheck();

	bool B_isAIlocked();

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void TankAimmingComponentSetup(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UTankBarrel * Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	FVector OutLaunchVelocity;

	UPROPERTY(BlueprintReadOnly)
	EFiringStatus firingstatus = EFiringStatus::Reloading;

	UPROPERTY(EditDefaultsOnly, category = "i")
		float ProjectileLaunchSpeed = 10000.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "i")
		TSubclassOf<AProjectile> projectile;

	UPROPERTY(EditDefaultsOnly, category = "i")
		float ReloadTime = 3;
	
	UPROPERTY(EditDefaultsOnly, category = "i")
		float PlayerLockTolerance = 2;
	UPROPERTY(EditDefaultsOnly, category = "i")
		float AILockTolerance = 5;

	float LastFireTime = 0;



private:

	bool isAIlocked;

	bool isPlayerlocked;

	bool isReloaded;
};
