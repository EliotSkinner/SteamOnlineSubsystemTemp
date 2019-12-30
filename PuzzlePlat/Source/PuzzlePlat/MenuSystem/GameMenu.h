// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMenuWidget.h"
#include "MenuInterface.h"
#include "GameMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLAT_API UGameMenu : public UGameMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

private:

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UFUNCTION()
	void ReopenMainMenu();

	UFUNCTION()
	void CancelPressed();
	
};
