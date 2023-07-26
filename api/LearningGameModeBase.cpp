// Copyright Epic Games, Inc. All Rights Reserved.


#include "LearningGameModeBase.h"
#include "Learning.h"

void ALearningGameModeBase::BeginPlay() {
	UE_LOG(LogTemp, Warning, TEXT("Message %d"), 1);

	UE_LOG(MyLog1, Display, TEXT("A display message, cutom log is working"));
	UE_LOG(MyLog1, Warning, TEXT("custom warning log is working"));
	UE_LOG(MyLog1, Error, TEXT("custom error log is working"));

	CreateLog(LoggerName);
	FMessageLog logger(LoggerName);
	logger.Warning(FTEXT("A warning Message from gamemode"));
	logger.Info(FTEXT("A info Message from gamemode"));
	logger.Error(FTEXT("A error Message from gamemode"));

	TSharedRef<IHttpRequest> http = FHttpModule::Get().CreateRequest();
	FHttpRequestCompleteDelegate& delegate = http->OnProcessRequestComplete();
	delegate.BindLambda([](FHttpRequestPtr request, FHttpResponsePtr response, bool success)->void {
		UE_LOG(LogTemp, Warning, TEXT("Http Response: %d, %s"),
		request->GetResponse()->GetResponseCode(),
		*request->GetResponse()->GetContentAsString());
		});

	http->SetURL(TEXT("http://unrealengine.com"));
	http->ProcessRequest();
}