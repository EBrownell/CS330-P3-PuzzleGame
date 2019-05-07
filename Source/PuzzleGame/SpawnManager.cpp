// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnManager.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();

	Spawn();
	
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnManager::Spawn()
{

	if (SpawnActor) {
		UWorld* World = GetWorld();
		if (World) {
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;	// prob change?
			SpawnParams.Instigator = Instigator;

			int i = FMath::RandHelper(TargetPoints.Num());
			FVector location = TargetPoints[i]->GetActorLocation();
			FRotator rotation = TargetPoints[i]->GetActorRotation();

			AActor* MyNewSpawnedActor = World->SpawnActor<AActor>(SpawnActor, location, rotation, SpawnParams);

			if (!MyNewSpawnedActor) {
				if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Failed to Spawn()"))); }
			}
		}
	}

}