// Fill out your copyright notice in the Description page of Project Settings.


#include "InterfaceGameModeBase.h"
#include "EngineUtils.h"


void AInterfaceGameModeBase::BeginPlay() {
	Super::BeginPlay();

	FTransform SpawnLocation;
	ASingleInterfaceActor* SpawnedActor = GetWorld()->SpawnActor<ASingleInterfaceActor>(ASingleInterfaceActor::StaticClass(), SpawnLocation);
	UClass* ActorClass = SpawnedActor->GetClass();

	if (ActorClass->ImplementsInterface(UMyInterface::StaticClass())) {
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawned actor implements interface!"));
	}

	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It) {
		AActor* Actor = *It;
		IMyInterface* MyInterfaceInstance = Cast<IMyInterface>(Actor);

		if (MyInterfaceInstance) {
			MyInterfaceInstances.Add(MyInterfaceInstance);
		}
	}
	FString Message = FString::Printf(TEXT("%d actors implement the interface"), MyInterfaceInstances.Num());
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, Message);
}