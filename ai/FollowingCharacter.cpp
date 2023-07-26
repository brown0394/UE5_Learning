// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowingCharacter.h"

// Sets default values
AFollowingCharacter::AFollowingCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFollowingCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFollowingCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto startPos = GetActorLocation();

	FVector playerPos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector direction = playerPos - startPos;
	direction.Normalize();

	SetActorLocation(startPos + direction);

}

// Called to bind functionality to input
void AFollowingCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

