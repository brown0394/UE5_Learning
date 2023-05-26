// Fill out your copyright notice in the Description page of Project Settings.


#include "Undead.h"

// Add default functionality here for any IUndead functions that are not pure virtual.

bool IUndead::IsDead() {
	return true;
}

void IUndead::Die() {
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Im already dead"));
}

void IUndead::Turn() {
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Im fleeing"));
}

void IUndead::Banish() {
	AActor* Me = Cast<AActor>(this);
	if (Me) {
		Me->Destroy();
	}
}