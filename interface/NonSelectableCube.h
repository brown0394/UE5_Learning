// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SelectableCube.h"
#include "NonSelectableCube.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API ANonSelectableCube : public ASelectableCube
{
	GENERATED_BODY()
public:
	ANonSelectableCube();
	virtual bool IsItSelectable() override;
	virtual bool TrySelect() override;
	virtual void Deselect() override;
};
