 // Copyright © Stephen Sterling 2024.  All rights reserved.

// This software and its contents are protected by copyright law and international treaties.
// Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.

#include "ZombieCharacter.h"


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
}

// Called when the game starts or when spawned
void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = CalmSpeed;
}

// Called every frame
void AZombieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bIsMoving = GetVelocity().Length() > 0;
	MovementSpeed = GetVelocity().Length();
	ZombieLocation = GetActorLocation();
	
}

 void AZombieCharacter::DealDamage()
 {
	UE_LOG(LogTemp, Warning, TEXT("Damage called"));
 }

void AZombieCharacter::StartAttack()
{
	if (bIsAttacking != true && AnimationMontages != nullptr)
	{
		bIsAttacking = true;
		PlayAnimationMontage(EAnimationType::Attack);
	}
}

 void AZombieCharacter::EndAttack()
 {
	UE_LOG(LogTemp, Display, TEXT("End Attack"));
	bIsAttacking = false;
 }

 void AZombieCharacter::PlayAnimationMontage(EAnimationType AnimationType) const
{
	 UE_LOG(LogTemp, Warning, TEXT("Called from PlayAnimationMontage"));

	// if there is not a montage to play or there is no mesh, just return 
	if (!AnimationMontages || !GetMesh()) return;
	
	UAnimMontage* MontageToPlay = nullptr;
	for (const FAnimationMontageData& Data : AnimationMontages->AnimationsArray)
	{
		if (Data.AnimationType == AnimationType)
		{
			MontageToPlay = Data.AnimationMontage;
			break;
		}
	}

	if (MontageToPlay)
	{
		if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
		{
			float Seconds = AnimInstance->Montage_Play(MontageToPlay);
			UE_LOG(LogAnimation, Warning, TEXT("Called from PlayAnimationMontage -- Seconds = %f"), Seconds);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT
			("Montage for animation type '%d' not found in Data Asset."),
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






