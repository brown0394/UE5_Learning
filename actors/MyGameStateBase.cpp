// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBase.h"

AMyGameStateBase::AMyGameStateBase() {
	this->CurrentScore = 0;
}

int32 AMyGameStateBase::GetScore() {
	return this->CurrentScore;
}

void AMyGameStateBase::SetScore(int32 NewScore) {
	this->CurrentScore = NewScore;
}