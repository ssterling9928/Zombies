// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Zombies/Zombie/ZombieAIController.h"
#include "ZombieAnimInstance.generated.h"

enum class EZombieState : uint8; 

UCLASS()
class ZOMBIES_API UZombieAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	
	// Movement Speed variable for the transition
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	float Speed;

	// Is the zombie attacking?
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	bool bIsAttacking;

	// Is the zombie dead?
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	bool bIsDead;

	// Is the zombie moving?
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	bool bIsMoving;

	// Is the zombie weak?
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	bool bIsWeak;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	AZombieAIController* ZombieAIController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	bool bIsAggressive;

	void virtual NativeUpdateAnimation(float DeltaSeconds) override;
};
