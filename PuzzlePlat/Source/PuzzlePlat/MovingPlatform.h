// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLAT_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

protected:

	virtual void Tick(float DeltaTime) override;

public:

	virtual void BeginPlay() override;

	AMovingPlatform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveableSpeed = 10.0;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

private:

	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;
};
