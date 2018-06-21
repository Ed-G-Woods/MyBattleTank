// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"


class AMassWheelConstraint;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UTankTrack();

	virtual void BeginPlay()override;

	float Throttle=0;

	float LastLandTime;

	bool isMWCfound = false;

	TArray<AMassWheelConstraint*> getMWC();
	TArray<AMassWheelConstraint*> MyMWC;

public:
	//Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable)
		void SetThrottle(float t);

	void MoveTrack(FVector force);
	
	UPROPERTY(EditDefaultsOnly)
		float DrivingForce = 40000000;

	int32 SpawnWheelNum;
	
};
