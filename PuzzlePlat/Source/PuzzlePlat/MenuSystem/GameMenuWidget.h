// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "GameMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLAT_API UGameMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetMenuInterface(IMenuInterface* MenuInterface);

	void Setup();

	void Teardown();

protected:

	IMenuInterface* MenuInterface;
};
