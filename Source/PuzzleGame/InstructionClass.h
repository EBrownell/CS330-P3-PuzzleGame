// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InstructionClass.generated.h"

UCLASS()
class PUZZLEGAME_API AInstructionClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInstructionClass();

	UPROPERTY(EditAnywhere)
		FString Instr;

	UPROPERTY(EditAnywhere)
		FString ControlText;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int32 i;
	FString TextInput;
	int32 timer;
	bool TimerOn;
	int32 activateTimer;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString getInstructions();

	FString getControlText();
};
