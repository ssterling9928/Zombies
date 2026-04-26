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
	
}

// Called when the game starts or when spawned
void AZombieAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerReference = GetWorld()->GetFirstPlayerController()->GetPawn();
	ZombieReference = Cast<AZombieCharacter>(GetPawn());
}

bool AZombieAIController::IsPlayerWithinAttackRange() const
{
	float DistanceFromCharacter = FVector::Dist(ZombieReference->GetActorLocation(), PlayerReference->GetActorLocation());
	return DistanceFromCharacter <= ZombieReference->GetAttackRange();
}
void AZombieAIController::AttackPlayer() const
{
	if (IsPlayerWithinAttackRange())
	{
		if (AAIController *AIController = Cast<AAIController>(ZombieReference->GetController()))
		{
			AIController->StopMovement();
		}

		ZombieReference->HandleAttack();
	}
}

void AZombieAIController::StopAttacking() const
{
	ZombieReference->StopAttack();
}

void AZombieAIController::MoveZombieTowardsPlayer()
{
	MoveToActor(PlayerReference, AcceptanceRadius);
}

// Called every frame
void AZombieAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsPlayerWithinAttackRange())
	{
		AttackPlayer();
	}	
	else if (PlayerReference)
	{	
		StopAttacking();
		MoveZombieTowardsPlayer();
	}
}



