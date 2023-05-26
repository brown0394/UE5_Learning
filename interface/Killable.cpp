// Fill out your copyright notice in the Description page of Project Settings.


#include "Killable.h"

// Add default functionality here for any IKillable functions that are not pure virtual.

bool IKillable::IsDead() {
	return false;
}

void IKillable::Die() {
	AActor* Me = Cast<AActor>(this);
	if (Me) {
		Me->Destroy();
	}
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Im dead now"));
}