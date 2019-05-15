// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WorldClock.h"
#include "InstructionClass.h"
#include "PuzzleGameHUD.generated.h"

UCLASS()
class APuzzleGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	APuzzleGameHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere)
		FString Instruction;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	UFont* Font;
	AWorldClock *Clock;
	int32 num;
	FString instructions[15];
	int32 i;
	FString TextInput;
	int32 timer;
	bool TimerOn;
	float alphaa;

};

