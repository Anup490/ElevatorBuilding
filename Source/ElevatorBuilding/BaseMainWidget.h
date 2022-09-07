// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseMainWidget.generated.h"

/**
 * 
 */
class UTextBlock;

UCLASS()
class ELEVATORBUILDING_API UBaseMainWidget : public UUserWidget
{
	GENERATED_BODY()

	void SetColorAndText(UTextBlock* FloorErrorText, FLinearColor&& Color, FString&& Text);
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Floors;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Basements;

	UFUNCTION(BlueprintCallable)
	void ClearErrorMessage(UTextBlock* Text);

	UFUNCTION(BlueprintCallable)
	void OnFloorCommit(UTextBlock* FloorErrorText, FText FloorCountText);

	UFUNCTION(BlueprintCallable)
	void OnBasementCommit(UTextBlock* BasementErrorText, FText BasementCountText);

public:
	UFUNCTION(BlueprintCallable)
	int GetCount();

	UFUNCTION(BlueprintCallable)
	void ClearCount();

	UFUNCTION(BlueprintCallable)
	int GetBasementCount();

	UFUNCTION(BlueprintCallable)
	void ClearBasementCount();
};
