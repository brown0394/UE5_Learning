// Fill out your copyright notice in the Description page of Project Settings.


#include "PostEditChangePropertyActor.h"

APostEditChangePropertyActor::APostEditChangePropertyActor() {
	PrimaryActorTick.bCanEverTick = true;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
	UStaticMeshComponent* SM = GetStaticMeshComponent();

	if (SM != nullptr) {
		if (MeshAsset.Object != nullptr) {
			SM->SetStaticMesh(MeshAsset.Object);
			SM->SetGenerateOverlapEvents(true);
		}
		SM->SetMobility(EComponentMobility::Movable);
	}
}

void APostEditChangePropertyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) {
	if (PropertyChangedEvent.Property != nullptr) {
		const FName PropertyName(PropertyChangedEvent.Property->GetName());

		if (PropertyName == GET_MEMBER_NAME_CHECKED(APostEditChangePropertyActor, ShowStaticMesh)) {
			UStaticMeshComponent* SM = GetStaticMeshComponent();

			if (SM != nullptr) {
				SM->SetVisibility(ShowStaticMesh);
			}
		}
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}