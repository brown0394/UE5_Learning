// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "Particles/ParticleSystem.h"
#include "GameplayTask_CreateParticles.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API UGameplayTask_CreateParticles : public UGameplayTask
{
	GENERATED_BODY()
public:
	virtual void Activate();

	UFUNCTION(BlueprintCallable, Category = "GameplayTask",
		meta = (AdvancedDisplay = "TasKOwner", DefaultToSelf = "TaskOwner", BlueprintInternalUseOnly = "TRUE"))
		static UGameplayTask_CreateParticles* ConstructTask(TScriptInterface<IGameplayTaskOwnerInterface>TaskOwner,
			UParticleSystem* particleSystem, FVector location);
	UParticleSystem* particleSystem;
	FVector Location;
};