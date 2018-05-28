// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"



void UTankTurret::AddYawRotation(float Speed)
{
	Speed = FMath::Clamp(Speed, -1.0f, 1.0f);
	float YawPerFrame = Speed * MaxDegreesPerSecond *GetWorld()->DeltaTimeSeconds;
	float NewYaw = RelativeRotation.Yaw + YawPerFrame;

	SetRelativeRotation(FRotator(0, NewYaw,0));

}
