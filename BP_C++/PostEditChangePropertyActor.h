// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "PostEditChangePropertyActor.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API APostEditChangePropertyActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	APostEditChangePropertyActor();

	UPROPERTY(EditAnywhere)
		bool ShowStaticMesh = true;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
