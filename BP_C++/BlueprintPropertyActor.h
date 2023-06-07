// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlueprintPropertyActor.generated.h"

UCLASS()
class LEARNING_API ABlueprintPropertyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlueprintPropertyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, Category = "CookBook")
		bool ReadWriteProperty;
	UPROPERTY(BlueprintReadOnly, Category = "CookBook")
		bool ReadOnlyProperty;
};
