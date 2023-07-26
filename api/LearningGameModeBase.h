// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HttpManager.h"
#include "HttpModule.h"
#include "HttpRetrySystem.h"
#include "Interfaces/IHttpResponse.h"
#include "LearningGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API ALearningGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		void BeginPlay();
};
