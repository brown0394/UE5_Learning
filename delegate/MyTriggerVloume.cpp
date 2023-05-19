// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerVloume.h"
#include "LearningGameModeBase.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AMyTriggerVloume::AMyTriggerVloume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(200, 200, 100));
}

// Called when the game starts or when spawned
void AMyTriggerVloume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerVloume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerVloume::NotifyActorBeginOverlap(AActor* OtherActor) {
	auto Message = FString::Printf(TEXT("%s entered me"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr) {
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		ALearningGameModeBase* MyGameMode = Cast<ALearningGameModeBase>(GameMode);
		if (MyGameMode != nullptr) {
			MyGameMode->MyStandardDelegate.ExecuteIfBound();
			auto Color = FLinearColor(1, 0, 0, 1);
			MyGameMode->MyParameterDelegate.ExecuteIfBound(Color);
			MyGameMode->MyMulticastDelegate.Broadcast();
			OnPlayerEntered.Broadcast();
		}
	}
}

void AMyTriggerVloume::NotifyActorEndOverlap(AActor* OtherActor) {
	auto Message = FString::Printf(TEXT("%s left me"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr) {
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		ALearningGameModeBase* MyGameMode = Cast<ALearningGameModeBase>(GameMode);
		if (MyGameMode != nullptr) {
			MyGameMode->MyStandardDelegate2.ExecuteIfBound();
		}
	}
}