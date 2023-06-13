// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"
#include "AbilitySystemComponent.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	abilitySystemComponent->BindToInputComponent(PlayerInputComponent);
	
	for (const FGameplayAbilityBindInfo& BindInfo : gamePlayAbilitySet->Abilities) {
		FGameplayAbilitySpec spec(BindInfo.GameplayAbilityClass->GetDefaultObject<UGameplayAbility>(), 1, (int32)BindInfo.Command);
		FGameplayAbilitySpecHandle abilityHandle = abilitySystemComponent->GiveAbility(spec);

		int32 AbilityId = (int32)BindInfo.Command;
		FGameplayAbilityInputBinds inputBinds(FS("ConfirmlTargetting_%s_%s", *GetName(), *(BindInfo.GameplayAbilityClass->GetName())),
			FS("CancelTargetting_%s_%s", *GetName(), *(BindInfo.GameplayAbilityClass->GetName())), "EGameplayAbilityInputBinds", AbilityId, AbilityId);
		abilitySystemComponent->BindAbilityActivationToInputComponent(PlayerInputComponent, inputBinds);
		abilitySystemComponent->TryActivateAbility(abilityHandle, 1);
	}
}

UAbilitySystemComponent* AWarrior::GetAbilitySystemComponent() const{
	return abilitySystemComponent;
}