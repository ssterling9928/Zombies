// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieSpawner.h"

// Sets default values
AZombieSpawner::AZombieSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ElapsedTime = 0;
	SpawnedZombiesCount = 0;
}

void AZombieSpawner::SpawnZombies()
{
	if (ElapsedTime >= SpawnInterval && MaxActiveZombies >= SpawnedZombiesCount)
	{
		// Create and initialize Spawn Parameters 
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = this;
		SpawnParameters.Instigator = GetInstigator();

		// Spawn Zombies
		AZombieCharacter* SpawnedZombie = GetWorld()->SpawnActor<AZombieCharacter>
		(GetRandomZombieToSpawn(), this->GetActorLocation(), FRotator::ZeroRotator, SpawnParameters);
		
		SpawnedZombiesCount++;
		ElapsedTime = 0;
	}
}

// Called when the game starts or when spawned
void AZombieSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombieSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ElapsedTime += DeltaTime;

	SpawnZombies();
}

TSubclassOf<AZombieCharacter> AZombieSpawner::GetRandomZombieToSpawn()
{
	return ZombiesToSpawn[FMath::RandRange(0, ZombiesToSpawn.Num()-1)];
}



