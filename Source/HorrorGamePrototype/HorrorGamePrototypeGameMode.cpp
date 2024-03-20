// Copyright Epic Games, Inc. All Rights Reserved.

#include "HorrorGamePrototypeGameMode.h"
#include "HorrorGamePrototypeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHorrorGamePrototypeGameMode::AHorrorGamePrototypeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
