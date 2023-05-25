// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Warrior.generated.h"

UCLASS()
class LEARNING_API AWarrior : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarrior();

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void OnOverlapBegin(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void OnOverlapEnd(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void PostInitializeComponents() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector2D lastInput;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Forward(float amount);
	void Backward(float amoint);
	void Left(float amount);
	void Right(float amount);
};
