// Copyright © 2024 Stephen Sterling.  All rights reserved.  This software and its contents are protected by copyright law and international treaties.  Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.


#include "FPS_PlayerController.h"
#include "EnhancedInputSubsystems.h"

AFPS_PlayerController::AFPS_PlayerController()
{
	
}

void AFPS_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add controls 
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}
