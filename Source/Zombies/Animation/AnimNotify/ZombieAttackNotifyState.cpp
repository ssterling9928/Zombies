// Copyright © 2024 Stephen Sterling.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#include "ZombieAttackNotifyState.h"
#include "Zombies/Zombie/ZombieAIController.h"
#include "Zombies/Zombie/ZombieCharacter.h"


void UZombieAttackNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                           float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	UE_LOG(LogTemp, Display, TEXT("NotifyBegin"));
	// check to make sure that it is a zombie calling the function
	if (AZombieCharacter* ZombieCharacter = Cast<AZombieCharacter>(MeshComp->GetOwner()))
	{
		// then get the AIController and call OnAttackNotify from the AIController 
		if (AZombieAIController* AIController = Cast<AZombieAIController>(ZombieCharacter->GetController()))
		{
			AIController->OnAttackNotify(); 
		}
	}
}

void UZombieAttackNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	// check to make sure that it is a zombie calling the function
	if (AZombieCharacter* ZombieCharacter = Cast<AZombieCharacter>(MeshComp->GetOwner()))
	{
		// then get the AIController and call OnAttackNotify from the AIController 
		if (AZombieAIController* AIController = Cast<AZombieAIController>(ZombieCharacter->GetController()))
		{
			AIController->OnAttackNotifyEnd(); 
		}
	}
}
