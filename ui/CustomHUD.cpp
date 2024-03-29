// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomHUD.h"
#include "Engine/Canvas.h"

void ACustomHUD::DrawHUD() {
	Super::DrawHUD();
	Canvas->DrawText(GEngine->GetSmallFont(), TEXT("Test string to be printed"), 10, 10);
	FCanvasBoxItem ProgressBar(FVector2D(5, 25), FVector2D(100, 5));
	Canvas->DrawItem(ProgressBar);
	DrawRect(FLinearColor::Blue, 5, 25, 50, 5);
}
