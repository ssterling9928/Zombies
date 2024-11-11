// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.


#include "ZombieAIController.h"


// Sets default values
AZombieAIController::AZombieAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentZombieState = EZombieState::Calm;
	ZombieCharRef = nullptr;
}

EZombieState AZombieAIController::GetZombieState() const
{
	return CurrentZombieState;
}

void AZombieAIController::SetZombieState(EZombieState NewState)
{
	if (ZombieCharRef == nullptr)
	{
		ZombieCharRef = Cast<AZombieCharacter>(GetPawn());
	}

	if (CurrentZombieState != NewState && ZombieCharRef)
	{
		CurrentZombieState = NewState;
		bool bNewAggressiveState = (CurrentZombieState == EZombieState::Aggressive);
		ZombieCharRef->SetIsAggressive(bNewAggressiveState);
	}
	
}

void AZombieAIController::OnAttack() const
{
	if (ZombieCharRef && !ZombieCharRef->IsAttacking())
	{
		ZombieCharRef->StartAttack();
	}
}

// Called when the game starts or when spawned
void AZombieAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerReference = GetWorld()->GetFirstPlayerController()->GetPawn();
	SetZombieState(EZombieState::Calm);
}

// Called every frame
void AZombieAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MoveToActor(PlayerReference, AcceptanceRadius);

	
	
}



