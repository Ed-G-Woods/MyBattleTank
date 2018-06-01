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


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimmingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimmingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
/*	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;*/

	void AimAt(FVector a,float LaunchSpeed);

	
	void MoveBarrelAndTurret(FVector AimDirection);

	bool islocked;

	UTankBarrel * Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	FVector OutLaunchVelocity;

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void TankAimmingComponentSetup(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	
	UPROPERTY(BlueprintReadOnly)
	EFiringStatus firingstatus = EFiringStatus::Reloading;

private:

	


};
