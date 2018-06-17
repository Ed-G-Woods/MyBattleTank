// Fill out your copyright notice in the Description page of Project Settings.

#include "WheelSpawn.h"
#include "MassWheelConstraint.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UWheelSpawn::UWheelSpawn()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWheelSpawn::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Warning, TEXT("SpawnWheel start"));
	MWC = GetWorld()->SpawnActorDeferred<AMassWheelConstraint>(MassWheelConstraint,GetComponentTransform());
	if (!MWC) { return; }
	MWC->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	UGameplayStatics::FinishSpawningActor(MWC, GetComponentTransform());
	UE_LOG(LogTemp, Warning, TEXT("SpawnWheel finish"));

}


// Called every frame
void UWheelSpawn::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

