// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_MoveToPlayer.h"
#include "EnemyAIController.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

EBTNodeResult::Type
UMyBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	auto EnemyController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	auto BlackBoard = OwnerComp.GetBlackboardComponent();

	ACharacter* Target = Cast<ACharacter>(BlackBoard->GetValue<UBlackboardKeyType_Object>(EnemyController->TargetId));
	if (Target) {
		EnemyController->MoveToActor(Target, 50.0f);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
