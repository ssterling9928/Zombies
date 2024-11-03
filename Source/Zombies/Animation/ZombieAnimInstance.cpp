// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieAnimInstance.h"
#include "Zombies/Zombie/ZombieCharacter.h"


void UZombieAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (APawn* OwningPawn = TryGetPawnOwner())
	{
		if (AZombieCharacter* ZombieCharacter = Cast<AZombieCharacter>(OwningPawn))
		{
			Speed = ZombieCharacter->GetVelocity().Size();
	
			bIsAttacking = ZombieCharacter->IsAttacking();
			bIsAttacking = ZombieCharacter->IsDead();
			bIsWalkingOrRunning = ZombieCharacter->IsWalkingOrRunning();
		}
	}
}
