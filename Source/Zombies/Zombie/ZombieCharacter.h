// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ZombieCharacter.generated.h"

UCLASS()
class ZOMBIES_API AZombieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieCharacter();

	// Property used to set animations for zombie walk/run
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zombies")
	float RunSpeed = 150;
	
	virtual void Tick(float DeltaTime) override;
	bool IsAttacking() const;
	bool IsDead() const;
	bool IsWalkingOrRunning() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:

	bool bIsAttacking;
	bool bIsDead;
	bool bIsWalkingOrRunning;
};
