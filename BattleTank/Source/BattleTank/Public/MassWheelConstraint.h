// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MassWheelConstraint.generated.h"

class UPhysicsConstraintComponent;
class USphereComponent;

UCLASS()
class BATTLETANK_API AMassWheelConstraint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMassWheelConstraint();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetupConstraint();

	void AddAxleForce(FVector Force);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
private:
	UPROPERTY(VisibleAnywhere)
		USphereComponent* Wheel;
	UPROPERTY(VisibleAnywhere)
		USphereComponent* Axle;
	UPROPERTY(VisibleAnywhere)
		UPhysicsConstraintComponent* PhysicsConstraint;
	UPROPERTY(VisibleAnywhere)
		UPhysicsConstraintComponent* AxleConstraint;
};
