// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickEventGameModeBase.h"

void AClickEventGameModeBase::BeginPlay() {
	Super::BeginPlay();

	Widget = SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)[
		SNew(SButton).OnClicked(FOnClicked::CreateUObject(this, &AClickEventGameModeBase::ButtonClicked)).Content()[
			SAssignNew(ButtonLabel, STextBlock).Text(FText::FromString(TEXT("Click here")))
		]
	];

	auto player = GetWorld()->GetFirstLocalPlayerFromController();

	GEngine->GameViewport->AddViewportWidgetForPlayer(player, Widget.ToSharedRef(), 1);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	auto pc = GEngine->GetFirstLocalPlayerController(GetWorld());
	
	EMouseLockMode lockMode = EMouseLockMode::DoNotLock;

	auto inputMode = FInputModeUIOnly().SetLockMouseToViewportBehavior(lockMode).SetWidgetToFocus(Widget);
	pc->SetInputMode(inputMode);
}

FReply AClickEventGameModeBase::ButtonClicked() {
	ButtonLabel->SetText(FText::FromString(TEXT("Clicked")));
	return FReply::Handled();
}