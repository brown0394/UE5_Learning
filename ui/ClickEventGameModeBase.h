// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SlateBasics.h"
#include "ClickEventGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API AClickEventGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
private:
	TSharedPtr<SVerticalBox> Widget;
	TSharedPtr<STextBlock> ButtonLabel;
public:
	virtual void BeginPlay() override;
	FReply ButtonClicked();

};
