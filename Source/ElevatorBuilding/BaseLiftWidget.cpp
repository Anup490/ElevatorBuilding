// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseLiftWidget.h"
#include "BaseLift.h"
#include "Internationalization/Text.h"
#include "Styling/SlateColor.h"
#include "Components/EditableText.h"


void UBaseLiftWidget::SetLift(ABaseLift* LiftObject)
{
	Lift = LiftObject;
}

void UBaseLiftWidget::OnClickGo(UEditableText* EditBlock)
{
	FString ValueInString = EditBlock->GetText().ToString();
	int Value = FCString::Atoi(*ValueInString);
	Lift->OnGo(Value);
}

