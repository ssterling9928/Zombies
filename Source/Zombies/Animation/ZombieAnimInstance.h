// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ZombieAnimInstance.generated.h"

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
	bool bIsWalkingOrRunning;
	
	// Override native update animation to update these variables
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
