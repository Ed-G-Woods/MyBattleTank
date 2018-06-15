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
	float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)override;
	
	
	FTankDelegate OnDie;

	UFUNCTION(BlueprintCallable)
		void Fire();
	void AimAt(FVector HitLocation);
	void FiringStateCheck();
	bool isAIAimmingLocked() const;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, category = "i")
		float TankMaxHP = 100;	//Default 100hp
	UPROPERTY(BlueprintReadOnly, category = "i")
		float TankHP;	//Default 100hp

	UPROPERTY(BlueprintReadWrite)
		UTankAimmingComponent* TankAimmingComponent = nullptr;

	

};
