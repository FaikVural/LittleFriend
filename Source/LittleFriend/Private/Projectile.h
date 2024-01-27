// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Projectile.generated.h"

class USoundCue;
class UNiagaraComponent;
class UNiagaraSystem;
class UBoxComponent;

UCLASS()
class AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
	virtual void Tick(float DeltaSeconds) override;
	
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void SpawnTrailSystem();
	void DestroyTimerFinished();
	void StartDestroyTimer();
	void ExplodeDamage();

	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactParticles;

	UPROPERTY(EditAnywhere)
	USoundCue* ImpactSound;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> TrailSystem;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> CollisionBox;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UParticleSystem> Tracer;

	UPROPERTY()
	TObjectPtr<UParticleSystemComponent> TracerComponent;

	UPROPERTY()
	TObjectPtr<UNiagaraComponent> TrailSystemComponent;

	UPROPERTY(EditAnywhere)
	float DestroyTime = 3.f;

	UPROPERTY(EditAnywhere)
	float Damage = 20.f;
	
	UPROPERTY(EditAnywhere)
	float DamageInnerRadius = 200.f;
	
	UPROPERTY(EditAnywhere)
	float DamageOuterRadius = 500.f;

	FTimerHandle DestroyTimer;
};
