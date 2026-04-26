// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#include "ZombieCharacter.h"
#include "Animation/ZombieAnimInstance.h"
#include "Animation/AnimationDataAsset.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AZombieCharacter::AZombieCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsAttacking = false;
	bIsDead = false;
	bIsMoving = false;
	bIsWeak = false;
	bIsAggressive = false;

	GetCharacterMovement()->MaxWalkSpeed = CalmSpeed;
}

// Called when the game starts or when spawned
void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
	AnimInstance = Cast<UZombieAnimInstance>(GetMesh()->GetAnimInstance());
	UE_LOG(LogTemp, Warning, TEXT("AttackRange = %f"), AttackRange);
}

// Called every frame
void AZombieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bIsMoving = GetVelocity().Length() > 0;
	MovementSpeed = GetVelocity().Length();

	WriteUILog();
}

void AZombieCharacter::WriteUILog()
{
	FString LogMessage = FString::Printf(TEXT("Zombie Location: %s | Speed: %f | IsAttacking: %s | IsDead: %s | IsMoving: %s | IsWeak: %s | IsAggressive: %s"),
		*GetActorLocation().ToString(),
		MovementSpeed,
		bIsAttacking ? TEXT("True") : TEXT("False"),
		bIsDead ? TEXT("True") : TEXT("False"),
		bIsMoving ? TEXT("True") : TEXT("False"),
		bIsWeak ? TEXT("True") : TEXT("False"),
		bIsAggressive ? TEXT("True") : TEXT("False"));

	GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, LogMessage);

	float DistanceFromCharacter = FVector::Dist(GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
	GEngine->AddOnScreenDebugMessage(2, 0.0f, FColor::Yellow, FString::Printf(TEXT("Distance from Player: %f"), DistanceFromCharacter));
}

void AZombieCharacter::HandleAttack()
{
	if (!bIsAttacking)
	{
		bIsAttacking = true;
		StartAttackAnimation();
	}
}

void AZombieCharacter::StopAttack()
{
	if (bIsAttacking)
	{
		bIsAttacking = false;
		StopAttackAnimation();
	}
}

void AZombieCharacter::DealDamage()
{
	UE_LOG(LogTemp, Warning, TEXT("Damage called"));
}

void AZombieCharacter::StartAttackAnimation()
{
	if (AnimationMontages != nullptr)
	{
		PlayAnimationMontage(EAnimationType::Attack);
	}
}

void AZombieCharacter::StopAttackAnimation()
{
	if (AnimationMontages != nullptr)
	{
		AnimInstance->Montage_Stop(0.2f, AnimationMontages->GetAnimationMontage(EAnimationType::Attack));	
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Cannot stop attack animation. Either not currently attacking or no AnimationMontages to play."));
	}
}

void AZombieCharacter::PlayAnimationMontage(EAnimationType AnimationType) const
{
    if (!AnimationMontages)
    {
        return;
    }

    UAnimMontage* MontageToPlay = AnimationMontages->GetAnimationMontage(AnimationType);

    if (!MontageToPlay)
    {
        return;
    }

    if (USkeletalMeshComponent* MeshComp = GetMesh())
    {
        if (UAnimInstance* CurrentAnimInstance = MeshComp->GetAnimInstance())
        {
            CurrentAnimInstance->Montage_Play(MontageToPlay);
        }
    }
}

void AZombieCharacter::SetIsAggressive(bool bNewIsAggressive)
{
	if (bIsAggressive != bNewIsAggressive)
	{
		bIsAggressive = bNewIsAggressive;
		GetCharacterMovement()->MaxWalkSpeed = bIsAggressive ? AggressiveSpeed : CalmSpeed;
	}
}
