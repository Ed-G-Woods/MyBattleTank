// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimmingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UTankAimmingComponent::UTankAimmingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimmingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...


	
}


void UTankAimmingComponent::AimAt(FVector a)
{
	if (!ensure(Barrel && Turret)) { return; }

	
	//FVector OutLaunchVelocity;
	FVector StarLocation = Barrel->GetSocketLocation(FName("FireLocation"));

	TArray<AActor*> actortoignore;


	bool AimRusult = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StarLocation,
		a,
		ProjectileLaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (AimRusult)
	{
		MoveBarrelAndTurret(OutLaunchVelocity);
	}
	else
	{
	}

	/*UE_LOG(LogTemp, Warning, TEXT("%s Aiming  %s"),*(GetOwner()->GetName()),*(OutLaunchVelocity.ToString()));*/


}

void UTankAimmingComponent::MoveBarrelAndTurret(FVector AimDirection)
{
	if (!ensure(Barrel && Turret)) { return; }

	FRotator BarrelRotatorNow = Barrel->GetForwardVector().Rotation();
	FRotator BarrelRotatorDesire = AimDirection.Rotation();

	if (GetOwner() == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		if (BarrelRotatorNow.Equals(BarrelRotatorDesire, PlayerLockTolerance)) {isPlayerlocked = true;}else {isPlayerlocked = false;}
	}
	else
	{
		if (BarrelRotatorNow.Equals(BarrelRotatorDesire, AILockTolerance)) { isAIlocked = true; }else { isAIlocked = false; }
	}
	
	
	Barrel->Elevate(BarrelRotatorDesire.Pitch - BarrelRotatorNow.Pitch);
	Turret->AddYawRotation(BarrelRotatorDesire.Yaw - BarrelRotatorNow.Yaw);

}

void UTankAimmingComponent::Fire()
{
	if (GetWorld()->GetTimeSeconds() - LastFireTime > ReloadTime && Ammo > 0)
	{
		SpawnProjectileAndLaunch();
		Ammo -= 1;
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
}

void UTankAimmingComponent::SpawnProjectileAndLaunch()
{
	auto P = GetWorld()->SpawnActor<AProjectile>(projectile,
		Barrel->GetSocketLocation(FName("FireLocation")),
		Barrel->GetSocketRotation(FName("FireLocation"))
		);

	P->LaunchProjectile(ProjectileLaunchSpeed);
}

void UTankAimmingComponent::FiringStateCheck()
{
	if (GetWorld()->GetTimeSeconds() - LastFireTime > ReloadTime)
	{
		isReloaded = true;
		if (isPlayerlocked)
		{
			firingstatus = EFiringStatus::Locked;
		}
		else
		{
			firingstatus = EFiringStatus::Aiming;
		}
	}
	else
	{
		isReloaded = false;
		firingstatus = EFiringStatus::Reloading;
	}
	if (Ammo == 0)
	{
		firingstatus = EFiringStatus::OutOfAmmo;
	}
}

bool UTankAimmingComponent::B_isAIlocked()
{
	return isAIlocked;
}

void UTankAimmingComponent::TankAimmingComponentSetup(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{


	Barrel = BarrelToSet;
	Turret = TurretToSet;
}


