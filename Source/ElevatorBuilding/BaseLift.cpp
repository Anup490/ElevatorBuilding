// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseLift.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "BaseLiftWidget.h"
#include "Kismet/GameplayStatics.h"
#include "BaseGameModeBase.h"
#include "BasePlayer.h"
#include "BaseLevel.h"

// Sets default values
ABaseLift::ABaseLift()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseLift::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseLift::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseLift::SaveObjectsAndOpenDoor(UStaticMeshComponent* Door, UBaseLiftWidget* HUD)
{
	LiftDoor = Door;
	LiftHUD = HUD;
	OpenDoor();
}

void ABaseLift::OpenDoor()
{
	LiftDoor->AddWorldOffset(FVector(200.0, 0.0, 0.0));
}

void ABaseLift::MoveUp()
{
	if (Player)
	{
		AddActorWorldOffset(FVector(0.0, 0.0, Speed));
		Player->AddActorWorldOffset(FVector(0.0, 0.0, Speed));
	}
}

void ABaseLift::MoveDown()
{
	if (Player)
	{
		AddActorWorldOffset(FVector(0.0, 0.0, -Speed));
		Player->AddActorWorldOffset(FVector(0.0, 0.0, -Speed));
	}
}

void ABaseLift::CloseDoor()
{
	LiftDoor->AddWorldOffset(FVector(-200.0, 0.0, 0.0));
}

void ABaseLift::ShowHUD()
{
	LiftHUD->AddToViewport();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}

void ABaseLift::HideHUD()
{
	LiftHUD->RemoveFromViewport();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}

void ABaseLift::StopLift()
{
	ShowHUD();
	OpenDoor();
}

bool ABaseLift::HasFloors()
{
	ABaseGameModeBase* GameMode = Cast<ABaseGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return GameMode->FloorCounter >= 0;
}

void ABaseLift::PrepareLift()
{
	CloseDoor();
	HideHUD();
}

bool ABaseLift::HasBasements()
{
	ABaseGameModeBase* GameMode = Cast<ABaseGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return GameMode->BasementCounter >= 0;
}

void ABaseLift::HandleLiftMovement()
{
	if (Inside && !ShouldStop)
	{
		if (TargetFloor > CurrentFloor)
		{
			MoveUp();
		}
		else if(TargetFloor < CurrentFloor)
		{
			MoveDown();
		}
	}
}

void ABaseLift::OnPlayerEnter(AActor* Actor)
{
	ABasePlayer* BasePlayer = Cast<ABasePlayer>(Actor);
	if (BasePlayer)
	{
		Player = BasePlayer;
		ShowHUD();
		Inside = true;
	}
}

void ABaseLift::OnPlayerExit(AActor* Actor)
{
	ABasePlayer* BasePlayer = Cast<ABasePlayer>(Actor);
	if (BasePlayer)
	{
		Player = 0;
		HideHUD();
		Inside = false;
	}
}

void ABaseLift::OnGo(int Floor)
{
	if ((CurrentFloor != Floor) && (HasFloors() || HasBasements()))
	{
		ABaseGameModeBase* GameMode = Cast<ABaseGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
		if ((Floor >= 0 && Floor <= GameMode->FloorCounter) || ((Floor * -1) <= GameMode->BasementCounter))
		{
			TargetFloor = Floor;
			PrepareLift();
			ShouldStop = false;
		}
	}
}

void ABaseLift::OnReachingFloor(AActor* Actor)
{
	ABaseLevel* Level = Cast<ABaseLevel>(Actor);
	if (Level)
		ShouldStop = (TargetFloor == Level->Floor);
	if (ShouldStop)
	{
		CurrentFloor = TargetFloor;
		StopLift();
	}
}