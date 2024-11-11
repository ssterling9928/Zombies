 // Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "ZombieCharacter.h"
#include "GameFramework/Actor.h"
#include "ZombieSpawner.generated.h"

UCLASS()
class ZOMBIES_API AZombieSpawner : public AActor
{
	GENERATED_BODY()

	
public:
	// Sets default values for this actor's properties
	AZombieSpawner();

	// TODO: Delete property, will create a blueprint that handles all
	//		 LocationActors and adds to spawner programmatically.
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AZombieCharacter>> ZombiesToSpawn;
	

	// TODO: Make this property a function to get a random interval 
	UPROPERTY(EditAnywhere)
	float SpawnInterval = 5.0f;

	UPROPERTY(EditAnywhere)
	int MaxActiveZombies = 15;
	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Returns a random AZombieCharacter Object to pass to Spawn Function
	TSubclassOf<AZombieCharacter> GetRandomZombieToSpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SpawnZombies();

private:

	float ElapsedTime;
	float SpawnedZombiesCount;
};
