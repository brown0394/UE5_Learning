// Fill out your copyright notice in the Description page of Project Settings.


#include "Selectable.h"

// Add default functionality here for any ISelectable functions that are not pure virtual.

bool ISelectable::IsItSelectable() {
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("It is Selectable"));
	return true;
}

bool ISelectable::TrySelect() {
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Accepting Selection"));
	return true;
}

void ISelectable::Deselect() {
	unimplemented();
}