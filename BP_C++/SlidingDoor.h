// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SlidingDoor.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API ASlidingDoor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	ASlidingDoor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Door)
		void Open();
	UPROPERTY()
		bool IsOpen;
	UPROPERTY()
		FVector TargetLocation;
};
