// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieAIController.h"


// Sets default values
AZombieAIController::AZombieAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AZombieAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerReference = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

// Called every frame
void AZombieAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToActor(PlayerReference, AcceptanceRadius);
}

