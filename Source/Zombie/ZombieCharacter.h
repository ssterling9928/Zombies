#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Animation/ZombieAnimationTypes.h"
#include "ZombieCharacter.generated.h"

class UAnimationDataAsset;
class UZombieAnimInstance;

UCLASS()
class ZOMBIES_API AZombieCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AZombieCharacter();

    virtual void Tick(float DeltaTime) override;

    bool IsAttacking() const { return bIsAttacking; }
    bool IsDead() const { return bIsDead; }
    bool IsMoving() const { return bIsMoving; }
    bool IsWeak() const { return bIsWeak; }
    bool IsAggressive() const { return bIsAggressive; }
    float GetMovementSpeed() const { return MovementSpeed; }
    float GetAttackRange() const { return AttackRange; }

    void WriteUILog();
    void DealDamage();
    void StartAttackAnimation();
    void StopAttackAnimation();
    void PlayAnimationMontage(EAnimationType AnimationType) const;
    void SetIsAggressive(bool bNewIsAggressive);

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation")
    TObjectPtr<UAnimationDataAsset> AnimationMontages = nullptr;

    UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category="Animation", meta=(AllowPrivateAccess="true"))
    TObjectPtr<UZombieAnimInstance> AnimInstance = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zombies")
    float CalmSpeed = 150.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zombies")
    float AggressiveSpeed = 300.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zombies", meta=(ClampMin="0", ClampMax="200"))
    float AttackRange = 110.f;

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Zombies", meta=(AllowPrivateAccess="true"))
    float MovementSpeed = 0.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Zombies", meta=(AllowPrivateAccess="true"))
    bool bIsAttacking = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Zombies", meta=(AllowPrivateAccess="true"))
    bool bIsDead = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Zombies", meta=(AllowPrivateAccess="true"))
    bool bIsMoving = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Zombies", meta=(AllowPrivateAccess="true"))
    bool bIsWeak = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Zombies", meta=(AllowPrivateAccess="true"))
    bool bIsAggressive = false;
};
