// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TankStatics.generated.h"

/**
 * 
 */
UCLASS()
class TANKPRATICES_API UTankStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Math")
	static float FindDeltaAngleDegrees(float A1, float A2);
	
	// Snap this actor to the Z plane that we're using for this level.
	UFUNCTION(BlueprintCallable, Category = "Tanks")
	static void PutInZPlane(AActor* ActorToMove);

	UFUNCTION(BlueprintCallable, Category = "Tanks")
	static class ATankPraticesGameModeBase* GetTanksGameMode(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Math|Rotator", meta = (Keywords = "Rotation"))
	static bool FindLookAtAngle2D(const FVector2D& Start, const FVector2D& Target, float& Angle);

	UFUNCTION(BlueprintCallable, Category = "Animation")
	static void PlayFlipbook(class UPaperFlipbookComponent* Component, class UPaperFlipbook* NewFlipbook, bool bLooping, float PlayRate = 1.0f, bool bPlayFromStart = false);
};
