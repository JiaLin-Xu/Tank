// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankPraticesGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TANKPRATICES_API ATankPraticesGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	ATankPraticesGameModeBase();

	UPROPERTY(EditAnywhere)
	float PlayInZPlane;
	
	
};
