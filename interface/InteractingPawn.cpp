// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractingPawn.h"

void AInteractingPawn::TryInteract() {
	APlayerController* MyController = Cast<APlayerController>(Controller);

	if (MyController) {
		APlayerCameraManager* MyCameraManager = MyController->PlayerCameraManager;
		auto StartLocation = MyCameraManager->GetCameraLocation();
		auto EndLocation = (MyCameraManager->GetActorForwardVector() * 100);

		FCollisionObjectQueryParams Params;
		FHitResult HitResult;

		GetWorld()->SweepSingleByObjectType(HitResult, StartLocation, EndLocation, FQuat::Identity,
			FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllObjects), FCollisionShape::MakeSphere(25),
			FCollisionQueryParams(FName("Interaction"), true, this));

		auto HitResultActor = HitResult.GetActor();
		if (HitResultActor != nullptr) {
			auto Class = HitResultActor->GetClass();
			if (Class->ImplementsInterface(UInteractable::StaticClass())) {
				if (IInteractable::Execute_CanInteract(HitResultActor)) {
					IInteractable::Execute_PerformInteract(HitResultActor);
				}
			}
		}
	}
}

void AInteractingPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent) {
	Super::SetupPlayerInputComponent(InInputComponent);
	InInputComponent->BindAction("Interact", IE_Released, this, &AInteractingPawn::TryInteract);
}