// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"

// Sets default values
ATimeManager::ATimeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATimeManager::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//Store the time that has been reverse
	if (TimeReverseEnable) {
		CurrentRecordedTime = FMath::Min(CurrentRecordedTime + DeltaSeconds * CurrentTimeFactor, ReverseTimeMaximum);
		if (CurrentRecordedTime <= 0.0f) {
			EndTimeReverse();
			CurrentRecordedTime = 0.0;
		}
	}
}

float ATimeManager::GetTimeFactor()
{
	return CurrentTimeFactor;
}

bool ATimeManager::GetTimeReverseAbility()
{
	return TimeReverseEnable && CurrentRecordedTime >= ReverseTimeThreshold;
}

float ATimeManager::GetCurrentReversableTime()
{
	return CurrentRecordedTime;
}

void ATimeManager::BeginTimeReverse()
{
	if (GetTimeReverseAbility()) {
		CurrentTimeFactor = ReverseTimeFactor;
	}
}

void ATimeManager::EndTimeReverse()
{
	CurrentTimeFactor = NormalTimeFactor;
}

void ATimeManager::EnableTimeReverse()
{
	if (!TimeReverseEnable)
		TimeReverseEnable = true;
}
void ATimeManager::DisableTimeReverse()
{
	if (TimeReverseEnable){
		EndTimeReverse();
		TimeReverseEnable = false;
		CurrentRecordedTime = 0.f;

	}
}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();

	//Apply normal time
	CurrentTimeFactor = NormalTimeFactor;
	
}



