// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Animation/AnimationDataAsset.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "ZombieCharacter.generated.h"


UCLASS()
class ZOMBIES_API AZombieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieCharacter();
	
	virtual void Tick(float DeltaTime) override;

	FVector ZombieLocation; // Location in the world of the zombie instance
	
	bool IsAttacking() const { return bIsAttacking; }
	bool IsDead() const { return bIsDead; }
	bool IsMoving() const { return bIsMoving; }
	bool IsWeak() const { return bIsWeak; }
	bool IsAggressive() const { return bIsAggressive; }
	float GetMovementSpeed() const { return MovementSpeed; }


	void DealDamage();
	void StartAttack();
	void EndAttack();
	void PlayAnimationMontage(EAnimationType AnimationType) const;

	UFUNCTION(BlueprintCallable, Category = "Zombie")
	void SetIsAggressive(bool bNewIsAggressive);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "0", ClampMax = "200"), Category = "Zombies")
	float AttackRange = 110;
	
protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimationDataAsset* AnimationMontages = nullptr;

	// Property used to set animations for zombie walk/run
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Zombies")
	float CalmSpeed = 150;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Zombies")
	float AggressiveSpeed = 300;
	
private:

	
	UPROPERTY(VisibleAnywhere, Category = "Zombies")
	float MovementSpeed = 0;

	UPROPERTY(VisibleAnywhere, Category = "Zombies")
	bool bIsAttacking;
	
	UPROPERTY(VisibleAnywhere, Category = "Zombies")
	bool bIsDead;
	
	UPROPERTY(VisibleAnywhere, Category = "Zombies")
	bool bIsMoving;
	
	UPROPERTY(VisibleAnywhere, Category = "Zombies")
	bool bIsWeak;
	
	UPROPERTY(VisibleAnywhere, Category = "Zombies")
	bool bIsAggressive;
};
