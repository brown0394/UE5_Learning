// Copyright Epic Games, Inc. All Rights Reserved.


#include "LearningGameModeBase.h"
#include "InventoryCharacter.h"

ALearningGameModeBase::ALearningGameModeBase() {
	DefaultPawnClass = AInventoryCharacter::StaticClass();
}