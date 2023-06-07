// Fill out your copyright notice in the Description page of Project Settings.


#include "OnConstructionActor.h"

AOnConstructionActor::AOnConstructionActor() {
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
	ShowStaticMesh = true;
}

void AOnConstructionActor::OnConstruction(const FTransform& Transform) {
	GetStaticMeshComponent()->SetVisibility(ShowStaticMesh);
}