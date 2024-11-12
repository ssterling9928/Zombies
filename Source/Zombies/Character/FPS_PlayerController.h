// Copyright © 2024 Stephen Sterling.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FPS_PlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class ZOMBIES_API AFPS_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* InputMappingContext;

	AFPS_PlayerController();

protected:
	virtual void BeginPlay() override;
	
};
