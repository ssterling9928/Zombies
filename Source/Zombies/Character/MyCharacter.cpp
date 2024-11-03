// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"

AMyCharacter::AMyCharacter()
{
	// Enable Crouching 
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
}


// Check to make sure character is using Enhanced Input Component, and if so, Bind Input Actions
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		
		if (EnhancedInputComponent != nullptr)
		{
			EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &AMyCharacter::CrouchCharacter);
			EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &AMyCharacter::StopCrouch);
		}
		
	}
}

void AMyCharacter::CrouchCharacter()
{
	// Call Unreal Made Crouch Function
	ACharacter::Crouch(false);
}

void AMyCharacter::StopCrouch()
{
	// Call Unreal Made Uncrouch Function 
	ACharacter::UnCrouch(false);
}

