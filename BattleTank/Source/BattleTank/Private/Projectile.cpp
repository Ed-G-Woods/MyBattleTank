// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Runtime/Engine/Classes/GameFramework/ProjectileMovementComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/RadialForceComponent.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	ProjectileMovement->bAutoActivate = false;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("CollisionMesh"));
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);
	RootComponent = CollisionMesh;

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchBlast"));
	LaunchBlast->SetupAttachment(RootComponent);

	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("ImpactBlast"));
	ImpactBlast->SetupAttachment(RootComponent);
	ImpactBlast->bAutoActivate = false;

	ExplosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("ExplosionRadial"));
	ExplosionForce->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}


void AProjectile::LaunchProjectile(float speed)
{
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
	ProjectileMovement->Activate(true);
}


void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (noDamageyet)
	{
		LaunchBlast->Deactivate();
		ImpactBlast->Activate();
		CollisionMesh->SetVisibility(false);
		CollisionMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		ExplosionForce->FireImpulse();

		UGameplayStatics::ApplyRadialDamage(this, ProjectileDamage, GetActorLocation(), ExplosionForce->Radius, UDamageType::StaticClass(), TArray<AActor*>());
		noDamageyet = false;
	}
}

