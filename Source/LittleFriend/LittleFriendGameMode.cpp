// Copyright Epic Games, Inc. All Rights Reserved.

#include "LittleFriendGameMode.h"
#include "LittleFriendCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALittleFriendGameMode::ALittleFriendGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
