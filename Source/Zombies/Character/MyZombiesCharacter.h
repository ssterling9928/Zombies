// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "Zombies/ZombiesCharacter.h"
#include "MyZombiesCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AMyZombiesCharacter : public AZombiesCharacter
{
	GENERATED_BODY()

public:
	
	AMyZombiesCharacter();
	
	// Created Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess=true))
	UInputAction* CrouchAction;

	
protected:

	// Function to Bind Input Actions
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// Function to Call Crouch Input Action
	void Crouch();

	// Function to Call to stop Crouch Input Action
	void StopCrouch();
	
};
