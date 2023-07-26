// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemeyCharacter.h"

// Sets default values
AEnemeyCharacter::AEnemeyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemeyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemeyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemeyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

