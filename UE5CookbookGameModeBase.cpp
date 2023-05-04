// Fill out your copyright notice in the Description page of Project Settings.


#include "UE5CookbookGameModeBase.h"
#include "MyFirstActor.h"

void AUE5CookbookGameModeBase::BeginPlay() {
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Spawning"));

	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnLocation);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AUE5CookbookGameModeBase::DestroyActorFunction, 10);
	
}

void AUE5CookbookGameModeBase::DestroyActorFunction() {
	if (SpawnedActor != nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Destroyed"));
		SpawnedActor->Destroy();
	}
}
