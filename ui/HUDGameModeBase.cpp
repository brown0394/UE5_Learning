// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDGameModeBase.h"
#include "CustomHUD.h"
#include "HUDPlayerController.h"

AHUDGameModeBase::AHUDGameModeBase() : Super(){
	HUDClass = ACustomHUD::StaticClass();
	PlayerControllerClass = AHUDPlayerController::StaticClass();
}
