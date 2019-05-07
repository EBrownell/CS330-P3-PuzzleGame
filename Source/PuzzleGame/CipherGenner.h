// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CipherGenner.generated.h"

UCLASS()
class PUZZLEGAME_API ACipherGenner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACipherGenner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	FString getCode();
	UFUNCTION(BlueprintCallable)
	int getCodePart(int n);
	UFUNCTION(BlueprintCallable)
		int getCodeLen();
	int CodeLen;
	FString Code;

};
