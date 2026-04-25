#pragma once

#include "CoreMinimal.h"
#include "ZombieAnimationTypes.generated.h"

UENUM(BlueprintType)
enum class EAnimationType : uint8
{
    Attack UMETA(DisplayName = "Attack"),
    Death  UMETA(DisplayName = "Death"),
    Jump   UMETA(DisplayName = "Jump"),
};
