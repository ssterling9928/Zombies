// Copyright © 2024 Stephen Sterling.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.


#include "FPS_PlayerController.h"
#include "EnhancedInputSubsystems.h"

AFPS_PlayerController::AFPS_PlayerController()
{
	// InputMappingContext will be assigned in Editor
	InputMappingContext = nullptr; 
}

void AFPS_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (InputMappingContext)
	{
		// get subsystem
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			// add controls 
			Subsystem->AddMappingContext(InputMappingContext, 0);
			UE_LOG(LogTemp, Warning, TEXT("Context Applied!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("InputMappingContext property is not assigned in the Details Panel."));
	}
} 
