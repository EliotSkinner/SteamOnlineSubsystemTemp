// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTigger.h"

#include "Components/BoxComponent.h"

#include "MovingPlatform.h"

// Sets default values
APlatformTigger::APlatformTigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	if (!ensure(TriggerVolume != nullptr)) return;

	RootComponent = TriggerVolume;


	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTigger::OnOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTigger::OnOverlapEnd);
}

// Called when the game starts or when spawned
void APlatformTigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformTigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlatformTigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	for (AMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->AddActiveTrigger();
	}
}

void APlatformTigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	for (AMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->RemoveActiveTrigger();
	}
}