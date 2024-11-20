// Copyright © 2024 Stephen Sterling.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ZombieAttackNotifyState.generated.h"

UCLASS()
class ZOMBIES_API UZombieAttackNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	virtual void NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, const FAnimNotifyEventReference& EventReference);
	
};
