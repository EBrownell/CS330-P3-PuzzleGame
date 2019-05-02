// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldClock.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AWorldClock::AWorldClock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

//	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
//	CountdownText->SetHorizontalAlignment(EHTA_Center);
//	CountdownText->SetWorldSize(150.0f);
//	RootComponent = CountdownText;
	CountdownTime = 1;
	seconds = 0;

	bool endTimer = false;
}

// Called when the game starts or when spawned
void AWorldClock::BeginPlay()
{
	Super::BeginPlay();
	
	//UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AWorldClock::AdvanceTimer, 1.0f, true);

}

// Called every frame
void AWorldClock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//CountDownTime += 1 * DeltaTime;
	/*if (CountDownTime >= 60) {
		CountDownTime = 0;
	}
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("Time: %d"), CountDownTime));
	}
	static const FString ScrollingMessage(TEXT("Hello World: "));

	if (GEngine)
	{
		const int32 AlwaysAddKey = -1; // Passing -1 means that we will not try and overwrite an
		// existing message, just add a new one
		GEngine->AddOnScreenDebugMessage(AlwaysAddKey, 0.5f, FColor::Yellow, ScrollingMessage + FString::FromInt(CountDownTime));

		const int32 MyNumberKey = 0; // Not passing -1 so each time through we will update the existing message instead
		// of making a new one
		GEngine->AddOnScreenDebugMessage(MyNumberKey, 5.f, FColor::Yellow, FString::FromInt(CountDownTime));

		CountDownTime += 1 * DeltaTime;
		//++CountDownTime; // Increase MyNumber so we can see it change on screen
	}*/
}

void AWorldClock::UpdateTimerDisplay()
{
	static const FString TimerText(TEXT("Time: "));
	//CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0)));
	if (CountdownTime < 10) {
		if (seconds < 10) {
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TimerText + "0" + FString::FromInt(CountdownTime) + ":0" + FString::FromInt(seconds));
			}
		}
		else {
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TimerText + "0" + FString::FromInt(CountdownTime) + ":" + FString::FromInt(seconds));
			}
		}
	}
	else {
		if (seconds < 10) {
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TimerText + FString::FromInt(CountdownTime) + ":0" + FString::FromInt(seconds));
			}
		}
		else {
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TimerText + FString::FromInt(CountdownTime) + ":" + FString::FromInt(seconds));
			}
		}
	}
}

void AWorldClock::AdvanceTimer()
{
	//--CountdownTime;
	--seconds;
	if (seconds < 0) {
		seconds = 59;
		--CountdownTime;
	}
	//UpdateTimerDisplay();
	if (CountdownTime < 0)
	{
		endTimer = true;
		// We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		//Perform any special actions we want to do when the timer ends.
		//CountdownHasFinished();
	}
}

void AWorldClock::CountdownHasFinished()
{
	static const FString GameOverText(TEXT("Game Over!"));
	//Change to a special readout
	//CountdownText->SetText(TEXT("Game Over"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, GameOverText);
	}
}

FString AWorldClock::GetTimerText()
{
	static const FString TimerText(TEXT("Time: "));
	if (CountdownTime < 10) {
		if (seconds < 10) {
			return TimerText + "0" + FString::FromInt(CountdownTime) + ":0" + FString::FromInt(seconds);
		}
		else {
			return TimerText + "0" + FString::FromInt(CountdownTime) + ":" + FString::FromInt(seconds);
		}
	}
	else {
		if (seconds < 10) {
			return TimerText + FString::FromInt(CountdownTime) + ":0" + FString::FromInt(seconds);
		}
		else {
			return TimerText + FString::FromInt(CountdownTime) + ":" + FString::FromInt(seconds);
		}
	}
}

bool AWorldClock::EndOfTimer()
{
	return endTimer;
}