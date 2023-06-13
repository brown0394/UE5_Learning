// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayAbilitySet.h"
#include "AbilitySystemInterface.h"
#include "Warrior.generated.h"

#define FS(x, ...) FString::Printf( TEXT(x) , __VA_ARGS__)

UCLASS()
class LEARNING_API AWarrior : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarrior();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		UGameplayAbilitySet* gamePlayAbilitySet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		UAbilitySystemComponent* abilitySystemComponent;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

};
