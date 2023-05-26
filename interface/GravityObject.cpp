// Fill out your copyright notice in the Description page of Project Settings.


#include "GravityObject.h"

// Add default functionality here for any IGravityObject functions that are not pure virtual.

void IGravityObject::EnableGravity() {
	AActor* ThisActor = Cast<AActor>(this);
	if (ThisActor != nullptr) {
		TArray<UPrimitiveComponent*> PrimitiveComponents;
		ThisActor->GetComponents(PrimitiveComponents);

		for (UPrimitiveComponent* Component : PrimitiveComponents) {
			Component->SetEnableGravity(true);
		}

		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Enabling Gravity"));
	}
}

void IGravityObject::DisableGravity() {
	AActor* ThisActor = Cast<AActor>(this);
	if (ThisActor != nullptr) {
		TArray<UPrimitiveComponent*> PrimitiveComponents;
		ThisActor->GetComponents(PrimitiveComponents);

		for (UPrimitiveComponent* Component : PrimitiveComponents) {
			Component->SetEnableGravity(false);
		}

		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Disabling Gravity"));
	}
}