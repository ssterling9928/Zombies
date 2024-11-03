// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "ZombieAIController.generated.h"

UCLASS()
class ZOMBIES_API AZombieAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AZombieAIController();

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
};
