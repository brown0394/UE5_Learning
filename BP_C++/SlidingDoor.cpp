// Fill out your copyright notice in the Description page of Project Settings.


#include "SlidingDoor.h"

ASlidingDoor::ASlidingDoor() {
	PrimaryActorTick.bCanEverTick = true;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	UStaticMeshComponent* SM = GetStaticMeshComponent();

	if (SM != nullptr) {
		if (MeshAsset.Object != nullptr) {
			SM->SetStaticMesh(MeshAsset.Object);
			SM->SetGenerateOverlapEvents(true);
		}
		SM->SetMobility(EComponentMobility::Movable);
		SM->SetWorldScale3D(FVector(0.3, 2, 3));
	}
	SetActorEnableCollision(true);

	IsOpen = false;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ASlidingDoor::BeginPlay() {
	Super::BeginPlay();
}

void ASlidingDoor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (IsOpen) {
		SetActorLocation(FMath::Lerp(GetActorLocation(), TargetLocation, 0.05));
	}
}

void ASlidingDoor::Open() {
	TargetLocation = ActorToWorld().TransformPositionNoScale(FVector(0, 0, 200));
	IsOpen = true;
}