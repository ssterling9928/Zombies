 // Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#include "ZombieAnimInstance.h"
#include "Zombie/ZombieCharacter.h"

void UZombieAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	ZombieCharacter = Cast<AZombieCharacter>(TryGetPawnOwner());
}	
void UZombieAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!ZombieCharacter)
	{
		return;
	}

	Speed = ZombieCharacter->GetMovementSpeed();
	bIsAttacking = ZombieCharacter->IsAttacking();
	bIsDead = ZombieCharacter->IsDead();
	bIsMoving = ZombieCharacter->IsMoving();
	bIsWeak = ZombieCharacter->IsWeak();
	bIsAggressive = ZombieCharacter->IsAggressive();
}