// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseGameModeBase.h"

void ABaseGameModeBase::SpawnUpperFloors(int Count, UClass* Type)
{
	ClearFloors();
	FVector Location = Loc.GetLocation();
	Location.X = -688.0;
	Location.Y = -400.0;
	Location.Z = 80.0;
	Loc.SetLocation(Location);
	FloorCounter = Count;
	for (int i=0; i<Count; i++)
	{
		ABaseLevel* Floor = Cast<ABaseLevel>(GetWorld()->SpawnActor(Type, &Loc));
		Floors.Add(Floor);
		Floor->SetFloorName(i + 1);
		Location = Loc.GetLocation();
		Location.Z += 200.0;
		Loc.SetLocation(Location);
	}
}

void ABaseGameModeBase::SpawnLowerBasements(int Count, UClass* Type)
{
	ClearBasements();
	FVector Location = BasementLoc.GetLocation();
	Location.X = -688.0;
	Location.Y = -400.0;
	Location.Z = -400.0;
	BasementLoc.SetLocation(Location);
	BasementCounter = Count;
	for (int i=0; i<Count; i++)
	{
		ABaseLevel* Basement = Cast<ABaseLevel>(GetWorld()->SpawnActor(Type, &BasementLoc));
		Basements.Add(Basement);
		Basement->SetFloorName((i + 1) * -1);
		Location = BasementLoc.GetLocation();
		Location.Z -= 200.0;
		BasementLoc.SetLocation(Location);
	}
}

void ABaseGameModeBase::ClearFloors()
{
	for (int i=0; i<FloorCounter; i++)
	{
		ABaseLevel* Floor = Floors.Pop();
		Floor->Destroy();
	}
}

void ABaseGameModeBase::ClearBasements()
{
	for (int i=0; i<BasementCounter; i++)
	{
		ABaseLevel* Basement = Basements.Pop();
		Basement->Destroy();
	}
}