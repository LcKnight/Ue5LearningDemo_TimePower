// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TimeManager.generated.h"

UCLASS()
class TIMEPOWER_API ATimeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeManager();

	UFUNCTION(BlueprintCallable)
	float GetTimeFactor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	// THis is the current active factor of time
	UPROPERTY(BlueprintReadOnly)

};
