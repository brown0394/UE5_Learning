// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"
#include "AbilitySystemComponent.h"
#include "GameUnitAttributeSet.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	abilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("UAbilitySystemComponent");
	GameplayTaskComponent = CreateDefaultSubobject<UGameplayTasksComponent>("UGameplayTasksComponent");

}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayTask_CreateParticles* task = UGameplayTask_CreateParticles::ConstructTask(this, particleSystem, FVector(200.f, 0.f, 200.f));
	if (GameplayTaskComponent && task) {
		GameplayTaskComponent->AddTaskReadyForActivation(*task);
	}
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

void AWarrior::PostInitializeComponents() {
	Super::PostInitializeComponents();

	if (abilitySystemComponent) {
		abilitySystemComponent->InitStats(UGameUnitAttributeSet::StaticClass(), NULL);
	}
}

inline UGameplayEffect* ConstructGameplayEffect(FString name) {
	return NewObject<UGameplayEffect>(GetTransientPackage(), FName(*name));
}

inline FGameplayModifierInfo& AddModifier(UGameplayEffect* Effect, FProperty* property, EGameplayModOp::Type Op,
	const FGameplayEffectModifierMagnitude& Magnitude) {
	
	int32 index = Effect->Modifiers.Num();
	Effect->Modifiers.SetNum(index + 1);
	FGameplayModifierInfo& Info = Effect->Modifiers[index];
	Info.ModifierMagnitude = Magnitude;
	Info.ModifierOp = Op;
	Info.Attribute.SetUProperty(property);
	return Info;
}

void AWarrior::TestGameplayEffect() {
	UGameplayEffect* RecoverHp = ConstructGameplayEffect("RecoverHp");
	FProperty* hpProperty = FindFieldChecked<FProperty>(UGameUnitAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UGameUnitAttributeSet, Hp));

	
	RecoverHp->DurationPolicy = EGameplayEffectDurationType::HasDuration;
	RecoverHp->DurationMagnitude = FScalableFloat(10.0f);

	RecoverHp->ChanceToApplyToTarget = 1.0f;
	RecoverHp->Period = 0.5f;
	AddModifier(RecoverHp, hpProperty, EGameplayModOp::Additive, FScalableFloat(50.0f));

}

UGameplayTasksComponent* AWarrior::GetGameplayTaskComponent(const UGameplayTask& task) const {
	return GameplayTaskComponent;
}

void AWarrior::OnTaskActivated(UGameplayTask& Task) {}

void AWarrior::OnTaskDeactivated(UGameplayTask& Task) {}

AActor* AWarrior::GetOwnerActor(const UGameplayTask* Task) const {
	return Task->GetOwnerActor();
}