// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyInterface.h"
#include "SingleInterfaceActor.h"
#include "InterfaceGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API AInterfaceGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void BeginPlay();

	TArray<IMyInterface*> MyInterfaceInstances;
};
