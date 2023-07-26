// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "EnemeyCharacter.h"
#include "BehaviorTree/BehaviorTree.h"

AEnemyAIController::AEnemyAIController() {
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void AEnemyAIController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);

	auto Characterr = Cast<AEnemeyCharacter>(InPawn);
	if (Characterr && Characterr->EnemyBehaviorTree) {
		BlackboardComp->InitializeBlackboard(*Characterr->EnemyBehaviorTree->BlackboardAsset);
		TargetId = BlackboardComp->GetKeyID("Target");
		BehaviorComp->StartTree(*Characterr->EnemyBehaviorTree);
	}
}