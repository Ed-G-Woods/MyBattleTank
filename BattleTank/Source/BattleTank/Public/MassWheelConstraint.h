// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MassWheelConstraint.generated.h"

class UPhysicsConstraintComponent;

UCLASS()
class BATTLETANK_API AMassWheelConstraint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMassWheelConstraint();
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
private:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mass;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Wheel;
	UPROPERTY(VisibleAnywhere)
		UPhysicsConstraintComponent* PhysicsConstraint;
};
