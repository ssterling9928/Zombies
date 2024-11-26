// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.


#include "ZombieAIController.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "Zombies/Animation/AnimNotify/ZombieAttackNotifyState.h"


// Sets default values
AZombieAIController::AZombieAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentZombieState = EZombieState::Calm;
}

EZombieState AZombieAIController::GetZombieState() const
{
	return CurrentZombieState;
}


void AZombieAIController::SetZombieState(EZombieState NewState)
{
	if (ZombieReference == nullptr)
	{
		ZombieReference = Cast<AZombieCharacter>(GetPawn());
	}

	if (CurrentZombieState != NewState && ZombieReference)
	{
		CurrentZombieState = NewState;
		bool bNewAggressiveState = (CurrentZombieState == EZombieState::Aggressive);
		ZombieReference->SetIsAggressive(bNewAggressiveState);
	}
	
}

void AZombieAIController::OnAttackNotify() const
{
	ZombieReference->DealDamage();
}

void AZombieAIController::OnAttackNotifyEnd() const
{
	ZombieReference->EndAttack();
}

// Called when the game starts or when spawned
void AZombieAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerReference = GetWorld()->GetFirstPlayerController()->GetPawn();
	SetZombieState(EZombieState::Calm);
}

void AZombieAIController::AttackPlayerIfWithinRange() const
{
	float DistanceFromCharacter = FVector::Dist(ZombieReference->ZombieLocation, PlayerReference->GetActorLocation());

	if (DistanceFromCharacter <= ZombieReference->AttackRange)
	{
		UE_LOG(LogAssetData, Warning, TEXT("Called from ZombieAI AttackPlayerIfWithinRange -- Distance from character is %f"), DistanceFromCharacter);
		ZombieReference->StartAttack();
	}
}

void AZombieAIController::MoveZombieTowardsPlayer()
{
	MoveToActor(PlayerReference, AcceptanceRadius);
}

// Called every frame
void AZombieAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MoveZombieTowardsPlayer();
	AttackPlayerIfWithinRange();
	
}



