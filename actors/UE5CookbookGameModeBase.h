// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyFirstActor.h"
#include "UE5CookbookGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API AUE5CookbookGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY()
		AMyFirstActor* SpawnedActor;

	UFUNCTION()
		void DestroyActorFunction();
	
};
