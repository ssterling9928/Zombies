// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZombiesGameMode.h"
#include "ZombiesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AZombiesGameMode::AZombiesGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
