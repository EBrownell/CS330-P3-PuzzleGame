// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include <EngineGlobals.h>							// for onscreen debug
#include <Runtime/Engine/Classes/Engine/Engine.h>	// for onscreen debug
#include "WorldClock.generated.h"

UCLASS()
class PUZZLEGAME_API AWorldClock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldClock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 CountdownTime;

	int32 seconds;
//	class UTextRenderComponent* CountdownText;
	void UpdateTimerDisplay();
	void AdvanceTimer();
	void CountdownHasFinished();
	FTimerHandle CountdownTimerHandle;
};
