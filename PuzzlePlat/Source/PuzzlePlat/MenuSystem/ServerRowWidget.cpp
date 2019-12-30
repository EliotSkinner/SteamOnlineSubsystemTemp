// Fill out your copyright notice in the Description page of Project Settings.

#include "ServerRowWidget.h"

#include "Components/Button.h"

#include "MainMenu.h"

void UServerRowWidget::Setup(class UMainMenu* InParent, uint32 InIndex)
{
	Parent = InParent;
	Index = InIndex;
	RowButton->OnClicked.AddDynamic(this, &UServerRowWidget::OnClicked);

}

void UServerRowWidget::OnClicked()
{
	Parent->SelectIndex(Index);
}