// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayTask_CreateParticles.h"
#include "Kismet/GameplayStatics.h"

UGameplayTask_CreateParticles* UGameplayTask_CreateParticles::ConstructTask(
	TScriptInterface<IGameplayTaskOwnerInterface> TaskOwner, UParticleSystem* particleSystem, FVector location
) {
	UGameplayTask_CreateParticles* task = NewTask<UGameplayTask_CreateParticles>(TaskOwner);
	if (task) {
		task->particleSystem = particleSystem;
		task->Location = location;
	}
	return task;
}

void UGameplayTask_CreateParticles::Activate() {
	Super::Activate();

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), particleSystem, Location);
}