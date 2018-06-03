// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:

	virtual void BeginPlay()override;

	float Throttle=0;

	float LastLandTime;

public:
	//Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable)
		void SetThrottle(float t);

	void MoveTrack();
	
	UPROPERTY(EditDefaultsOnly)
		float DrivingForce = 40000000;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
