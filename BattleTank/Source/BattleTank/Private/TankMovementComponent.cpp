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
// 
// 	if (s>0)
// 	{
// 		L_Track->SetThrottle(-s*2);
// 		R_Track->SetThrottle(s*2);
// 	}
// 	else if(s<0)
// 	{
// 		L_Track->SetThrottle(-s * 2);
// 		R_Track->SetThrottle(s * 2);
// 	}
	L_Track->SetThrottle(-s);
	R_Track->SetThrottle(s);
}

void UTankMovementComponent::Initialise(UTankTrack* L_Track, UTankTrack* R_Track)
{
	
	this->L_Track = L_Track;
	this->R_Track = R_Track;

}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("RequestDirectMove-"));
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();
	
	float dot = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(dot);
	UE_LOG(LogTemp, Warning, TEXT("RequestDirectMove-%s"), *FString::SanitizeFloat(dot));
	FVector cross= FVector::CrossProduct( AIForwardIntention, TankForward);
	IntendToTurn(cross.Z);


}

