// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnimationDataAsset.generated.h"


// Enum type for animation montage
UENUM(BlueprintType)
enum class EAnimationType : uint8
{
	Attack UMETA(DisplayName = "Attack"),
	Death UMETA(DisplayName = "Death"),
	Jump UMETA(DisplayName = "Jump"),
};


// struct for data asset
USTRUCT(BlueprintType)
struct FAnimationMontageData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAnimationType AnimationType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* AnimationMontage;
	
};


UCLASS(BlueprintType)
class ZOMBIES_API UAnimationDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAnimationMontageData> AnimationsArray;
};
