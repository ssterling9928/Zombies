// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#include "AnimationDataAsset.h"
#include "Animation/AnimMontage.h"

UAnimMontage *UAnimationDataAsset::GetAnimationMontage(EAnimationType AnimationType) const
{
    for (const FAnimationMontageData& Entry : AnimationsArray)
    {
        if (Entry.AnimationType == AnimationType)
        {
            return Entry.AnimationMontage;
        }
    }
    return nullptr;
}
