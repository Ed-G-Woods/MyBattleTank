// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
class UParticleSystemComponent;
class URadialForceComponent;

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	void LaunchProjectile(float);

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditDefaultsOnly)
		float ProjectileDamage=20;

private:

	UProjectileMovementComponent * ProjectileMovement;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CollisionMesh;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* LaunchBlast;
	
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* ImpactBlast;

	UPROPERTY(VisibleAnywhere)
	URadialForceComponent* ExplosionForce;

	bool noDamageyet = true;

};
