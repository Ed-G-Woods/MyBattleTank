// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimmingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimmingComponent::UTankAimmingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimmingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimmingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimmingComponent::AimAt(FVector a,float LaunchSpeed)
{
	
	FVector OutLaunchVelocity;
	FVector StarLocation = Barrel->GetSocketLocation(FName("FireLocation"));

	TArray<AActor*> actortoignore;

	UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StarLocation,
		a,
		LaunchSpeed,
		false,
		0.0,
		0.0,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		actortoignore,
		true
	);


	UE_LOG(LogTemp, Warning, TEXT("%s Aiming  %s"),*(GetOwner()->GetName()),*(OutLaunchVelocity.ToString()));

}

void UTankAimmingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

