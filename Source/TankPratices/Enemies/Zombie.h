// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DamageInterface.h"
#include "Zombie.generated.h"

class ATank;

UCLASS()
class TANKPRATICES_API AZombie : public APawn, public IDamageInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AZombie();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Zombie", meta = (ClampMin = "0.0"))
	int32 Health;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "AI")
	void SetTarget(AActor* NewTarget);

	UFUNCTION(BlueprintCallable, Category = "AI")
	AActor* GetTarget();

	//UFUNCTION(BlueprintCallable, Category = "AI")
	//ATank* GetTargetAsTank();

	//UFUNCTION(BlueprintNativeEvent, Category = "AI")
	//void ZombieAI(float DeltaSeconds);
	//virtual void ZombieAI_Implementation(float DeltaSeconds);

	//UFUNCTION(BlueprintNativeEvent, Category = "AI")
	//bool ZombieAIShouldAttack();
	//virtual bool ZombieAIShouldAttack_Implementation();

	//UFUNCTION(BlueprintImplementableEvent, Category = "AI")
	//void ZombieWalk(float DeltaSeconds, FVector DistanceWalkedThisFrame);

	//UFUNCTION(BlueprintImplementableEvent, Category = "AI")
	//void ZombieAttack(float DeltaSeconds);

	//UFUNCTION(BlueprintImplementableEvent, Category = "AI")
	//void ZombieDie(EDamageType DamageType);


	//~ Begin IDamageInterface
	virtual void ReceiveDamage(int32 IncomingDamage, EDamageType DamageType) override;
	virtual int32 GetHealthRemaining() override;
	//~ End IDamageInterface

private:
	UPROPERTY(VisibleInstanceOnly, Category = "AI")
	AActor* TargetActor;
	UPROPERTY(VisibleInstanceOnly, Categroy = "AI")
	ATank* TargetTank;

};
