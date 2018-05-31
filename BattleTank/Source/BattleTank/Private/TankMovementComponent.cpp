// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"


void UTankMovementComponent::IntendMoveForward(float s)
{
	//UE_LOG(LogTemp, Warning, TEXT("IntendMoveForward : %f"), s)

	L_Track->SetThrottle(s);
	R_Track->SetThrottle(s);

}

void UTankMovementComponent::IntendToTurn(float s)
{


	L_Track->SetThrottle(-s);
	R_Track->SetThrottle(s);
}

void UTankMovementComponent::Initialise(UTankTrack* L_Track, UTankTrack* R_Track)
{
	
	this->L_Track = L_Track;
	this->R_Track = R_Track;
}
