// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseMainWidget.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"
#include "Styling/SlateColor.h"


void UBaseMainWidget::ClearErrorMessage(UTextBlock* Text)
{
	Text->SetText(FText::FromString(""));
}

void UBaseMainWidget::OnFloorCommit(UTextBlock* FloorErrorText, FText FloorCountText)
{
	FString FloorCountString = FloorCountText.ToString();
	int FloorCount = FCString::Atoi(*FloorCountString);
	if (FloorCount >= 0)
	{
		Floors = FloorCount;
		SetColorAndText(FloorErrorText, FLinearColor(0.0, 1.0, 0.0), "Value is acceptable");
	}
	else
		SetColorAndText(FloorErrorText, FLinearColor(1.0, 0.0, 0.0), "Value must be positive");
}

void UBaseMainWidget::OnBasementCommit(UTextBlock* BasementErrorText, FText BasementCountText)
{
	FString BasementCountString = BasementCountText.ToString();
	int BasementCount = FCString::Atoi(*BasementCountString);
	if (BasementCount >= 0)
	{
		Basements = BasementCount;
		SetColorAndText(BasementErrorText, FLinearColor(0.0, 1.0, 0.0), "Value is acceptable");
	}
	else
		SetColorAndText(BasementErrorText, FLinearColor(1.0, 0.0, 0.0), "Value must be positive");
}

void UBaseMainWidget::SetColorAndText(UTextBlock* FloorErrorText, FLinearColor&& Color, FString&& Text)
{
	FloorErrorText->SetColorAndOpacity(FSlateColor(Color));
	FloorErrorText->SetText(FText::FromString(Text));
}

int UBaseMainWidget::GetCount()
{
	return Floors;
}

void UBaseMainWidget::ClearCount()
{
	Floors = 0;
}

int UBaseMainWidget::GetBasementCount()
{
	return Basements;
}

void UBaseMainWidget::ClearBasementCount()
{
	Basements = 0;
}