// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LearningGameModeBase.generated.h"

/**
 * 
 */
DECLARE_DELEGATE(FStandardDelegateSignature)
UCLASS()
class LEARNING_API ALearningGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	FStandardDelegateSignature MyStandardDelegate;
	FStandardDelegateSignature MyStandardDelegate2;
};
