// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.


#include "ZombieAIController.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "Animation/AnimNotify/ZombieAttackNotifyState.h"


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

	if (CurrentZombieState != NewState && ZombieReference)
	{
		CurrentZombieState = NewState;
		bool bIsNewStateAggressive = (CurrentZombieState == EZombieState::Aggressive);
		ZombieReference->SetIsAggressive(bIsNewStateAggressive);
	}
	
}

void AZombieAIController::OnAttackNotify() const
{
	ZombieReference->DealDamage();
}

void AZombieAIController::OnAttackNotifyEnd() const
{
	ZombieReference->StopAttackAnimation();
}

// Called when the game starts or when spawned
void AZombieAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerReference = GetWorld()->GetFirstPlayerController()->GetPawn();
	ZombieReference = Cast<AZombieCharacter>(GetPawn());
}

void AZombieAIController::AttackPlayerIfWithinRange() const
{
	float DistanceFromCharacter = FVector::Dist(ZombieReference->GetActorLocation(), PlayerReference->GetActorLocation());
	
	if (DistanceFromCharacter <= ZombieReference->GetAttackRange())
	{
		ZombieReference->StartAttackAnimation();
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



