// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Animation/ZombieAnimationTypes.h"
#include "AnimationDataAsset.generated.h"

class UAnimMontage;

// struct for data asset
USTRUCT(BlueprintType)
struct FAnimationMontageData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	EAnimationType AnimationType = EAnimationType::Attack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	TObjectPtr<UAnimMontage> AnimationMontage = nullptr;
};

UCLASS(BlueprintType)
class ZOMBIES_API UAnimationDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	TArray<FAnimationMontageData> AnimationsArray;

	UFUNCTION(BlueprintCallable, Category = "Animation")
	UAnimMontage *GetAnimationMontage(EAnimationType AnimationType) const;
};
