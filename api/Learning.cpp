// Copyright Epic Games, Inc. All Rights Reserved.

#include "Learning.h"
#include "Modules/ModuleManager.h"
#include "MessageLog/Public/MessageLogModule.h"
//#include "MessageLog.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Learning, "Learning" );
DEFINE_LOG_CATEGORY(MyLog1);

FName LoggerName("MessageLogLearning");
void CreateLog(FName logName) {
	FMessageLogModule& MessageLogModule = FModuleManager::LoadModuleChecked<FMessageLogModule>("MessageLog");
	FMessageLogInitializationOptions InitOptions;
	InitOptions.bShowPages = true;
	InitOptions.bShowFilters = true;
	FText LogListingName = FTEXT("Learning's log Listing");
	MessageLogModule.RegisterLogListing(logName, LogListingName, InitOptions);
}