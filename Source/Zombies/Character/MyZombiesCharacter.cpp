// Fill out your copyright notice in the Description page of Project Settings.


#include "MyZombiesCharacter.h"

#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"

AMyZombiesCharacter::AMyZombiesCharacter()
{
	// Enable Crouching 
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
}


// Check to make sure character is using Enhanced Input Component, and if so, Bind Input Actions
void AMyZombiesCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		
		if (EnhancedInputComponent != nullptr)
		{
			EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &AMyZombiesCharacter::Crouch);
			EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &AMyZombiesCharacter::StopCrouch);
		}
		
	}
}

void AMyZombiesCharacter::Crouch()
{
	// Call Unreal Made Crouch Function
	ACharacter::Crouch();
}

void AMyZombiesCharacter::StopCrouch()
{
	// Call Unreal Made Uncrouch Function 
	ACharacter::UnCrouch();
}

