// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"
#include "MassWheelConstraint.h"
#include "WheelSpawn.h"


void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

	//MyMWC = getMWC();

}

TArray<AMassWheelConstraint*> UTankTrack::getMWC() const
{

	TArray<AMassWheelConstraint*> MassWheelConstraintArray;
	TArray<USceneComponent*> WheelSpawnArray;
	GetChildrenComponents(false, WheelSpawnArray);
	for (USceneComponent* WheelSpawn : WheelSpawnArray)
	{
	
		auto mwc = Cast<UWheelSpawn>(WheelSpawn)->MWC;
		MassWheelConstraintArray.Add(mwc);
	}
	
	return MassWheelConstraintArray;
}

void UTankTrack::SetThrottle(float t)
{
	auto Force = GetForwardVector() * t * DrivingForce;
	MoveTrack(Force);
}

void UTankTrack::MoveTrack(FVector force)
{
	if (!isMWCfound) { MyMWC = getMWC(); isMWCfound = true; }
	for (AMassWheelConstraint* MWC:MyMWC)
	{
		MWC->AddAxleForce(force/4);
	}
}

