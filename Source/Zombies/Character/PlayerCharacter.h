// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Zombies/ZombiesCharacter.h"
#include "PlayerCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

UCLASS()
class APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	APlayerCharacter();
	FVector PlayerLocation; // Location of the player in world 

	// Jump Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	// Move Input Action 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	
	// Crouch Input Action 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess= "true"))
	UInputAction* CrouchAction;

	// Look Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

protected:

	// Function to bind Input Actions
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaTime) override;
	
private:
	
	// Crouch Function - Called from InputAction
	void CrouchCharacter();

	// Stop Crouch Function - Called from InputAction
	void StopCrouch();

	// Move Function - Called from InputAction
	void Move(const FInputActionValue& Value);

	// Look Function - Called from InputAction
	void Look(const FInputActionValue& Value);
	
	

	UPROPERTY(EditAnywhere, Category = "Zombie")
	float Health;
	
};
