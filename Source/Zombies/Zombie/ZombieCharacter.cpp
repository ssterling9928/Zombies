// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieCharacter.h"


// Sets default values
AZombieCharacter::AZombieCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AZombieCharacter::IsAttacking() const
{
	return bIsAttacking;
}

bool AZombieCharacter::IsDead() const
{
	return bIsDead;
}

bool AZombieCharacter::IsWalkingOrRunning() const
{
	return bIsWalkingOrRunning;
}


