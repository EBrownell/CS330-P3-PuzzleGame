// Fill out your copyright notice in the Description page of Project Settings.

#include "InstructionClass.h"

// Sets default values
AInstructionClass::AInstructionClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Instr = "What are you doing in bed so late?\n Find the key to the door and get to work.";
	i = 0;
	TextInput = "";
	timer = 0;
	TimerOn = true;
	activateTimer = 0;
	ControlText = "Press E to interact with objects.";
}

// Called when the game starts or when spawned
void AInstructionClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInstructionClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TextInput;

	// draw instructions
	if (i < Instr.Len() && timer % 2 == 0 && TimerOn) {
		if (Instr[i] == '\n') {
			//            TextInput = "";
			TimerOn = false;
		}
		else {
			TextInput += Instr[i];
		}
		i++;
	}
	if (TimerOn) {
		timer++;
	}
	if (!TimerOn) {
		activateTimer++;
		if (activateTimer >= 8) {
			ControlText = "";
		}
		if (activateTimer >= 12) {
			TimerOn = true;
			TextInput = "";
			activateTimer = 0;
		}
	}

	if (i >= Instr.Len()) {
		TimerOn = false;
		if (TimerOn) {
			TextInput = "";
		}
	}
}

FString AInstructionClass::getInstructions()
{
	return TextInput;
}

FString AInstructionClass::getControlText()
{
	return ControlText;
}
