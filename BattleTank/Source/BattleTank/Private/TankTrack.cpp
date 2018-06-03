// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"



void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::SetThrottle(float t)
{
	if (GetWorld()->GetTimeSeconds() - LastLandTime < 3* GetWorld()->GetDeltaSeconds())
	{
		auto Force = GetForwardVector() * t * DrivingForce;
		auto ForeLocation = GetComponentLocation();
		auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
		AddForceAtLocation(Force, ForeLocation);

		//UE_LOG(LogTemp, Warning, TEXT("time = %f ,%s Land"), GetWorld()->GetTimeSeconds(), *GetOwner()->GetName())
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("time = %f ,%s Fall"), GetWorld()->GetTimeSeconds(), *GetOwner()->GetName())
	}
	
}

void UTankTrack::MoveTrack()
{

	UE_LOG(LogTemp, Warning, TEXT("throttle = %f ") ,Throttle)
	//TankRoot->AddForceAtLocation(Force, ForeLocation);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	LastLandTime = GetWorld()->GetTimeSeconds();

}
