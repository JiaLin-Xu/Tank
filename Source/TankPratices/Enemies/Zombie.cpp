// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombie.h"


// Sets default values
AZombie::AZombie()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZombie::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AZombie::ReceiveDamage(int32 IncomingDamage, EDamageType DamageType)
{
	if (IncomingDamage >= Health)
	{
		if (Health >= 0)
		{
			Health = -1;
		}
		return;
	}
	Health -= IncomingDamage;
}

int32 AZombie::GetHealthRemaining()
{
	return Health;
}

void AZombie::SetTarget(AActor* NewTarget)
{
	//TargetActor = NewTarget;
	//TargetTank = Cast<ATank>(NewTarget);
}

AActor* AZombie::GetTarget()
{
	return TargetActor;
}