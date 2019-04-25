// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "PuzzleGameGameMode.h"
#include "PuzzleGameHUD.h"
#include "PuzzleGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

APuzzleGameGameMode::APuzzleGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APuzzleGameHUD::StaticClass();
}
