// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeGameModeBase.h"

void AAttributeGameModeBase::BeginPlay() {
	Super::BeginPlay();

	Widget = SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)[
		SNew(SButton).Content()[
			SNew(STextBlock).Text(TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateUObject(
				this, &AAttributeGameModeBase::GetButtonLabel)))
		]
	];
	GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(),
		Widget.ToSharedRef(), 1);
}

FText AAttributeGameModeBase::GetButtonLabel() const {
	FVector ActorLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	return FText::FromString(FString::Printf(TEXT("%f, %f, %f"), ActorLocation.X, ActorLocation.Y, ActorLocation.Z));
}