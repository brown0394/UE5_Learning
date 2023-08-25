// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SlateBasics.h"
#include "AttributeGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API AAttributeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	TSharedPtr<SVerticalBox> Widget;
	FText GetButtonLabel() const;
public:
	virtual void BeginPlay();
};
