// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseLift.generated.h"

UCLASS()
class ELEVATORBUILDING_API ABaseLift : public AActor
{
	GENERATED_BODY()

	const float Speed = 1.0;
	bool Inside = false;
	bool ShouldStop = true;
	int TargetFloor = 0;
	int CurrentFloor = 0;
	class UStaticMeshComponent* LiftDoor = 0;
	class UBaseLiftWidget* LiftHUD = 0;
	class ABasePlayer* Player = 0;
public:	
	// Sets default values for this actor's properties
	ABaseLift();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SaveObjectsAndOpenDoor( UStaticMeshComponent* Door, UBaseLiftWidget* HUD);

	UFUNCTION(BlueprintCallable)
	void OpenDoor();

	UFUNCTION(BlueprintCallable)
	void MoveUp();

	UFUNCTION(BlueprintCallable)
	void MoveDown();

	UFUNCTION(BlueprintCallable)
	void CloseDoor();

	UFUNCTION(BlueprintCallable)
	void ShowHUD();

	UFUNCTION(BlueprintCallable)
	void HideHUD();

	UFUNCTION(BlueprintCallable)
	void StopLift();

	UFUNCTION(BlueprintCallable)
	bool HasFloors();

	UFUNCTION(BlueprintCallable)
	void PrepareLift();

	UFUNCTION(BlueprintCallable)
	bool HasBasements();

	UFUNCTION(BlueprintCallable)
	void HandleLiftMovement();

	UFUNCTION(BlueprintCallable)
	void OnPlayerEnter(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void OnPlayerExit(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void OnReachingFloor(AActor* Actor);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OnGo(int Floor);
};
