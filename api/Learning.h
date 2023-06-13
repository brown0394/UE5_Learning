// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#define LOCTEXT_NAMESPACE "LearningNamespace"
#define FTEXT(x) LOCTEXT(x, x)

extern FName LoggerName;

void CreateLog(FName logName);

DECLARE_LOG_CATEGORY_EXTERN(MyLog1, Log, All);