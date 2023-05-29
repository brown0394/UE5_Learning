// Fill out your copyright notice in the Description page of Project Settings.


#include "NonSelectableCube.h"

ANonSelectableCube::ANonSelectableCube() : Super() {}

bool ANonSelectableCube::IsItSelectable() {
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("It is not Selectable"));
	return false;
}

bool ANonSelectableCube::TrySelect() {
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Selection Refused"));
	return false;
}

void ANonSelectableCube::Deselect() {
	unimplemented();
}