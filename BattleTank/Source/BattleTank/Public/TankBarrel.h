// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent),hidecategories = ("Collision"), hidecategories = ("Lighting"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void Elevate(float Speed);

	UPROPERTY(EditAnywhere)
		float MaxPitch = 40;
	UPROPERTY(EditAnywhere)
		float MinPitch = 0;

};
