// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree.h"

ATree::ATree() {
	PrimaryActorTick.bCanEverTick = true;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	UStaticMeshComponent* SM = GetStaticMeshComponent();

	if (SM != nullptr) {
		if (MeshAsset.Object != nullptr) {
			SM->SetStaticMesh(MeshAsset.Object);
			SM->SetGenerateOverlapEvents(true);
		}
		SM->SetMobility(EComponentMobility::Movable);
	}
}