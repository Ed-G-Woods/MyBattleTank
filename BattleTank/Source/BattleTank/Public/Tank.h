// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankMovementComponent;
class UTankAimmingComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	FTankDelegate OnDie;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
		void Fire();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly,category = "i")
		float TankMaxHP = 100;	//Default 100hp
	UPROPERTY(BlueprintReadOnly, category = "i")
		float TankHP ;	//Default 100hp


	void FiringStateCheck();

	bool isAIAimmingLocked() const;

	float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite)
		UTankAimmingComponent* TankAimmingComponent = nullptr;

};
