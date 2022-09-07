// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseLiftWidget.generated.h"

/**
 * 
 */
UCLASS()
class ELEVATORBUILDING_API UBaseLiftWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class ABaseLift* Lift;

	UFUNCTION(BlueprintCallable)
	void OnClickGo(class UEditableText* EditBlock);
public:
	UFUNCTION(BlueprintCallable)
	void SetLift(ABaseLift* LiftObject);
};
