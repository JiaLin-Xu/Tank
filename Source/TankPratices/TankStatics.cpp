// Fill out your copyright notice in the Description page of Project Settings.

#include "TankStatics.h"
#include "TankPraticesGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbookComponent.h"


float UTankStatics::FindDeltaAngleDegrees(float A1, float A2)
{
	float Delta = A2 - A1;
	if (Delta > 180.f)
	{
		 Delta -= 360.0f;
	}
	else if (Delta < -180.f)
	{
		Delta += 360.0f;
	}
	return Delta;
}

ATankPraticesGameModeBase* UTankStatics::GetTanksGameMode(UObject* WorldContextObject)
{
	return Cast<ATankPraticesGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject));
}

void UTankStatics::PutInZPlane(AActor* ActorToMove)
{
	if (ATankPraticesGameModeBase* GM = UTankStatics::GetTanksGameMode(ActorToMove))
	{
		FVector Loc = ActorToMove->GetActorLocation();
		Loc.Z = GM->PlayInZPlane;
		ActorToMove->SetActorLocation(Loc);
	}
}

bool UTankStatics::FindLookAtAngle2D(const FVector2D& Start, const FVector2D& Target, float& Angle)
{
	FVector2D Normal = (Target - Start).GetSafeNormal();
	if (!Normal.IsNearlyZero())
	{
		Angle = FMath::RadiansToDegrees(FMath::Atan2(Normal.Y, Normal.X));
		return true;
	}
	return false;
}

void UTankStatics::PlayFlipbook(UPaperFlipbookComponent* Component, UPaperFlipbook* NewFlipbook, bool bLooping, float PlayRate, bool bPlayFromStart)
{
	Component->SetFlipbook(NewFlipbook);
	Component->SetLooping(bLooping);
	Component->SetPlayRate(PlayRate);
	if (bPlayFromStart)
	{
		Component->PlayFromStart();
	}
	else
	{
		Component->Play();
	}
}
