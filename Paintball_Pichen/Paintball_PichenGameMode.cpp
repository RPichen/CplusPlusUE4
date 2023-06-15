// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Paintball_PichenGameMode.h"
#include "Paintball_PichenHUD.h"
#include "Paintball_PichenCharacter.h"
#include "UObject/ConstructorHelpers.h"

APaintball_PichenGameMode::APaintball_PichenGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APaintball_PichenHUD::StaticClass();
}
