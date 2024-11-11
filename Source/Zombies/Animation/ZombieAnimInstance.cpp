 // Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#include "ZombieAnimInstance.h"


void UZombieAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (APawn* OwningPawn = TryGetPawnOwner())
	{
		if (const AZombieCharacter* ZombieCharacter = Cast<AZombieCharacter>(OwningPawn))
		{
			// TODO: Implement where animation variables will update on their own based on input into animation preview
			Speed = ZombieCharacter->GetMovementSpeed();
			bIsAttacking = ZombieCharacter->IsAttacking();
			bIsDead = ZombieCharacter->IsDead();
			bIsMoving = ZombieCharacter->IsMoving();
			bIsWeak = ZombieCharacter->IsWeak();
			bIsAggressive = ZombieCharacter->IsAggressive();
			ZombieAIController = Cast<AZombieAIController>(ZombieCharacter->GetController());
		}
	}
	GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, FString::Printf(TEXT("Speed: %f"), Speed), false);
}
