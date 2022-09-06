// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseMenuArea.generated.h"

UCLASS()
class ELEVATORBUILDING_API ABaseMenuArea : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseMenuArea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ShowHUD(class UBaseMainWidget* Menu);

	UFUNCTION(BlueprintCallable)
	void HideHUD(class UBaseMainWidget* Menu);

	UFUNCTION(BlueprintCallable)
	void OnOverlapEnd(class UBaseMainWidget* Menu);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
