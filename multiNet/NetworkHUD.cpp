// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkHUD.h"
#include"Engine/Canvas.h"
#include "LearningCharacter.h"

void ANetworkHUD::DrawHUD() {
	Super::DrawHUD();

	ALearningCharacter* PlayerCharacter = Cast<ALearningCharacter>(GetOwningPawn());

	if (PlayerCharacter) {
		Canvas->DrawText(GEngine->GetMediumFont(), FString::Printf(TEXT("Called jump %d times"),
			PlayerCharacter->JumpCurrentCount), 10, 10);
	}
}
