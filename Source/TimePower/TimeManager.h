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

	void Tick(float DeltaSeconds) override;

public:
	UFUNCTION(BlueprintCallable)
	float GetTimeFactor();

	UFUNCTION(BlueprintCallable)
	bool GetTimeReverseAbility();

	UFUNCTION(BlueprintCallable)
	float GetCurrentReversableTime();

	//Time Reverse control
	UFUNCTION(BlueprintCallable)
	void BeginTimeReverse();

	UFUNCTION(BlueprintCallable)
	void EndTimeReverse();

	UFUNCTION(BlueprintCallable)
	void EnableTimeReverse();
	UFUNCTION(BlueprintCallable)
	void DisableTimeReverse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// THis is the current active factor of time
	//UPROPERTY(BlueprintReadOnly)
protected:
	// This is the current states
	UPROPERTY(BlueprintReadOnly)
	float CurrentTimeFactor = 1.0f;

	UPROPERTY(BlueprintReadOnly)
	float CurrentRecordedTime = 0.0f;

	//TIme reverse ability
	UPROPERTY(BlueprintReadOnly)
	bool TimeReverseEnable = false;




public:
	//global presets
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float NormalTimeFactor = 1.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ReverseTimeFactor = -3.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float ReverseTimeThreshold = 3.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float ReverseTimeMaximum = 15.0f;


};
