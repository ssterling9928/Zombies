// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "ZombieCharacter.h"
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

	EZombieState GetZombieState() const;
	void SetZombieState(EZombieState NewState);
	void OnAttackNotify() const;
	void OnAttackNotifyEnd() const; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere)
	APawn* PlayerReference = nullptr;

	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 1.0;

	UPROPERTY(VisibleAnywhere)
	AZombieCharacter* ZombieCharRef;
	
	EZombieState CurrentZombieState;
};
