// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Zombie/ZombieCharacter.h"
#include "ZombieAIController.generated.h"


UENUM(BlueprintType)
enum class EZombieState : uint8
{
	Calm UMETA(DisplayName = "Calm"),
	Aggressive UMETA(DisplayName = "Aggressive")
};


UCLASS()
class ZOMBIES_API AZombieAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AZombieAIController();

	virtual void Tick(float DeltaTime) override;

	EZombieState GetZombieState() const;
	void OnAttackNotify() const;
	void OnAttackNotifyEnd() const; 

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool IsPlayerWithinAttackRange() const;
	void AttackPlayer() const;
	void StopAttacking() const;
	void MoveZombieTowardsPlayer();
	void SetZombieState(EZombieState NewState);

	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 1.0;
	

private:

	UPROPERTY()  //  Created "UPROPERTY" to deal with Garbage Collection issue
	APawn* PlayerReference;

	UPROPERTY()  //  Created "UPROPERTY" to deal with Garbage Collection issue
	AZombieCharacter* ZombieReference;

	EZombieState CurrentZombieState;
	
};
