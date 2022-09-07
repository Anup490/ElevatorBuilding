// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseLevel.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ABaseLevel::ABaseLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseLevel::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseLevel::SetFloorValues(int Value, FString Type, UTextRenderComponent* TextRender)
{
	Floor = Value;
	if (Value < 0) Value *= -1;
	Type.AppendInt(Value);
	TextRender->SetText(Type);
}

