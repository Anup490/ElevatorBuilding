// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseLevel.h"
#include "BaseGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ELEVATORBUILDING_API ABaseGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTransform Loc;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<ABaseLevel*> Floors;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTransform BasementLoc;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<ABaseLevel*> Basements;

	UFUNCTION(BlueprintCallable)
	void SpawnUpperFloors(int Count, UClass* Type);

	UFUNCTION(BlueprintCallable)
	void SpawnLowerBasements(int Count, UClass* Type);
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int FloorCounter = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int BasementCounter = 0;

	UFUNCTION(BlueprintCallable)
	void ClearFloors();

	UFUNCTION(BlueprintCallable)
	void ClearBasements();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnFloors(int Count);

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnBasements(int Count);
};
