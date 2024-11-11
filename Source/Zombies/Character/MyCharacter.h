// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Zombies/ZombiesCharacter.h"
#include "MyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AMyCharacter : public AZombiesCharacter
{
	GENERATED_BODY()

public:
	
	AMyCharacter();
	
	// Created Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess=true))
	UInputAction* CrouchAction;

	
protected:

	// Function to Bind Input Actions
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	
private:
	// Function to Call Crouch Input Action
	void CrouchCharacter();

	// Function to Call to stop Crouch Input Action
	void StopCrouch();

	UPROPERTY(EditAnywhere, Category = "Zombie")
	float Health;
	
};
