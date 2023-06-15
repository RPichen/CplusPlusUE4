// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinalProjectGAM31GameMode.h"
#include "FinalProjectGAM31HUD.h"
#include "FinalProjectGAM31Character.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"

AFinalProjectGAM31GameMode::AFinalProjectGAM31GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFinalProjectGAM31HUD::StaticClass();
}

void AFinalProjectGAM31GameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AFinalProjectGAM31Character>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AFinalProjectGAM31GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetWorld()->GetMapName();

	if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}
}

EGamePlayState AFinalProjectGAM31GameMode::GetCurrentState() const
{
	return CurrentState;
}

void AFinalProjectGAM31GameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AFinalProjectGAM31GameMode::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
	case EGamePlayState::EPlaying:
	{
		// do nothing
	}
	break;
	// Unknown/default state
	case EGamePlayState::EGameOver:
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
	break;
	// Unknown/default state
	default:
	case EGamePlayState::EUnknown:
	{
		// do nothing
	}
	break;
	}
}