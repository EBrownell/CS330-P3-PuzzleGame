// Fill out your copyright notice in the Description page of Project Settings.

#include "CipherGenner.h"

// Sets default values
ACipherGenner::ACipherGenner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CodeLen = 4;
}

// Called when the game starts or when spawned
void ACipherGenner::BeginPlay()
{
	Super::BeginPlay();
	Code = "";
	for (int i = 0; i < CodeLen; ++i) {
		Code = Code + FString::FromInt(FMath::RandRange(0, 9));
	}
}

// Called every frame
void ACipherGenner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString ACipherGenner::getCode() {
	return Code;
}
int ACipherGenner::getCodeLen() {
	return CodeLen;
}

int ACipherGenner::getCodePart(int n) {
	if (n <= CodeLen && n > 0) {
		return Code[n - 1] - '0';
	}
	return 0;
}