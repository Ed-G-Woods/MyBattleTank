// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"



void UTankBarrel::Elevate(float Speed)
{
	//UE_LOG(LogTemp, Warning, TEXT("Elevateing....."));

	Speed = FMath::Clamp(Speed, -1.0f, 1.0f);

	float DegreesPerFrame = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewPitch = FMath::Clamp(RelativeRotation.Pitch + DegreesPerFrame, MinPitch, MaxPitch);
	
	SetRelativeRotation(FRotator(NewPitch, 0, 0));

}
