// Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#include "ZombieCharacter.h"
#include "Animation/ZombieAnimInstance.h"
#include "Animation/AnimationDataAsset.h"
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

void AZombieCharacter::DealDamage()
{
	UE_LOG(LogTemp, Warning, TEXT("Damage called"));
}

void AZombieCharacter::StartAttackAnimation()
{
	if (bIsAttacking != true && AnimationMontages != nullptr)
	{
		bIsAttacking = true;
		PlayAnimationMontage(EAnimationType::Attack);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("bIsAttacking is already TRUE or No AnimationMontages to Play"));
	}
}

void AZombieCharacter::StopAttackAnimation()
{
	if (bIsAttacking && AnimationMontages != nullptr)
	{
		bIsAttacking = false;
		
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Cannot stop attack animation. Either not currently attacking or no AnimationMontages to play."));
	}
}

void AZombieCharacter::PlayAnimationMontage(EAnimationType AnimationType) const
{
	UE_LOG(LogTemp, Warning, TEXT("Called from PlayAnimationMontage"));

	// if there is not a montage to play or there is no mesh, just return
	if (!AnimationMontages)
		return;

	UAnimMontage *MontageToPlay = nullptr;
	for (const FAnimationMontageData &Data : AnimationMontages->AnimationsArray)
	{
		if (Data.AnimationType == AnimationType)
		{
			MontageToPlay = Data.AnimationMontage;
			break;
		}
	}

	if (MontageToPlay)
	{
		if (AnimInstance)
		{
			AnimInstance->Montage_Play(MontageToPlay);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Montage for animation type '%d' not found in Data Asset."),
			   static_cast<int32>(AnimationType));
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
