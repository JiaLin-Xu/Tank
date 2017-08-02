// Fill out your copyright notice in the Description page of Project Settings.

#include "Missile.h"
#include "TimerManager.h"
#include "DamageInterface.h"
#include "Engine/World.h"

// Sets default values
AMissile::AMissile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 400.0f;
	Radius = 20.0f;
	DirectDamage = 5;
}

// Called when the game starts or when spawned
void AMissile::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(ExplodeTimerHandle, this, &AMissile::Explode, 0.5f);
}

// Called every frame
void AMissile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetTransform().GetUnitAxis(EAxis::X).ToString());
	FVector Loc = GetActorLocation();
	FVector DesiredEndLoc = Loc + (GetTransform().GetUnitAxis(EAxis::X) * (DeltaTime * Speed));
	FHitResult HitResult;
	FCollisionShape CollisionShape;

	if (Radius > 0.0f)
	{
		if (UWorld* World = GetWorld())
		{
			CollisionShape.SetCapsule(Radius, 200.0f);
			if (World->SweepSingleByProfile(HitResult, Loc, DesiredEndLoc, FQuat::Identity, MovementCollisionProfile, CollisionShape))
			{
				SetActorLocation(HitResult.Location);
				if (IDamageInterface* DamageActor = Cast<IDamageInterface>(HitResult.Actor.Get()))
				{
					DamageActor->ReceiveDamage(DirectDamage, EDamageType::HitWithMissile);
				}
				Explode();
			}
			else
			{
				SetActorLocation(DesiredEndLoc);
			}
		}
	}
}

void AMissile::Explode()
{
	GetWorldTimerManager().ClearTimer(ExplodeTimerHandle);
	OnExplode();
}

void AMissile::OnExplode_Implementation()
{
	Destroy();
}
