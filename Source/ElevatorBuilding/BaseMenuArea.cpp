// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseMenuArea.h"
#include "BaseMainWidget.h"
#include "BaseGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseMenuArea::ABaseMenuArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseMenuArea::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseMenuArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseMenuArea::ShowHUD(UBaseMainWidget* Menu)
{
	Menu->AddToViewport();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}

void ABaseMenuArea::HideHUD(class UBaseMainWidget* Menu)
{
	Menu->RemoveFromViewport();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
}

void ABaseMenuArea::OnOverlapEnd(class UBaseMainWidget* Menu)
{
	HideHUD(Menu);
	ABaseGameModeBase* GameMode = Cast<ABaseGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	int FloorCount = Menu->GetCount();
	int BasementCount = Menu->GetBasementCount();
	if (FloorCount >= 0)
	{
		GameMode->SpawnFloors(FloorCount);
		Menu->ClearCount();
	}
	if (BasementCount >= 0)
	{
		GameMode->SpawnBasements(BasementCount);
		Menu->ClearBasementCount();
	}
}

