// Copyright Epic Games, Inc. All Rights Reserved.


#include "LearningGameModeBase.h"
#include "Blueprint/UserWidget.h"

void ALearningGameModeBase::ButtonClicked() {
	UE_LOG(LogTemp, Warning, TEXT("UI Button Clicked"));
}

void ALearningGameModeBase::BeginPlay() {
	Super::BeginPlay();

	if (Widget) {
		UUserWidget* Menu = CreateWidget<UUserWidget>(GetWorld(), Widget);

		if (Menu) {
			Menu->AddToViewport();
			GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
		}
	}
}