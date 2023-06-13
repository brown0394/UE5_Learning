// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility_Attack.h"

bool UGameplayAbility_Attack::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const {

	UE_LOG(LogTemp, Warning, TEXT("ability_attack CanActivateAbility!"));
	return true;
}

bool UGameplayAbility_Attack::CheckCost(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	OUT FGameplayTagContainer* OptionalRelevantTags) const {

	UE_LOG(LogTemp, Warning, TEXT("ability_attack CheckCost!"));
	return true;
}

void UGameplayAbility_Attack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) {

	UE_LOG(LogTemp, Warning, TEXT("Activating ugameplayability_attack().. actor swings weapon"));
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UGameplayAbility_Attack::InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo) {

	UE_LOG(LogTemp, Warning, TEXT("ability_attack Input Pressed!"));
	Super::InputPressed(Handle, ActorInfo, ActivationInfo);
}