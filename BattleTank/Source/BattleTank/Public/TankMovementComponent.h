// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(meta  = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void IntendMoveForward(float s);

	UFUNCTION(BlueprintCallable)
		void IntendToTurn(float s);

	UTankTrack* L_Track;
	UTankTrack* R_Track;
	
	UFUNCTION(BlueprintCallable)
		void Initialise(UTankTrack* L_Track, UTankTrack* R_Track);


};
