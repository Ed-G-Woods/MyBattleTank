// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"
#include "MassWheelConstraint.h"
#include "WheelSpawn.h"


UTankTrack::UTankTrack()
{
	SpawnWheelNum = 0;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

	//MyMWC = getMWC();

}

TArray<AMassWheelConstraint*> UTankTrack::getMWC() 
{
	SpawnWheelNum = 0;
	TArray<AMassWheelConstraint*> MassWheelConstraintArray;
	TArray<USceneComponent*> WheelSpawnArray;
	GetChildrenComponents(false, WheelSpawnArray);
	for (USceneComponent* WheelSpawn : WheelSpawnArray)
	{
		SpawnWheelNum ++;
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
	if (!isMWCfound) 
	{
		MyMWC = getMWC(); 
		//isMWCfound = true; 
		UE_LOG(LogTemp, Warning, TEXT("SpawnWheelNum = %s ,MyMWC.Num = %s"),*(FString::FromInt(SpawnWheelNum)),* (FString::FromInt(MyMWC.Num())));

		MyMWC.Num() == SpawnWheelNum ? isMWCfound = true : isMWCfound = false;

	}
	for (AMassWheelConstraint* MWC:MyMWC)
	{
		MWC->AddAxleForce(force/ SpawnWheelNum /2);
		//UE_LOG(LogTemp, Warning, TEXT("AddForce-%s"), *GetOwner()->GetName());
	}
}

