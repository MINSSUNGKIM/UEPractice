// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../GameInfo.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UEPRACTICE_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float mMoveSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float mDir;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<TObjectPtr<UAnimMontage>> mAttackMontageArray;
	//공격 몽타주 재생위한 인덱스
	int32 mAttackIndex = 0;
	//공격 가능 상황판단 변수
	bool mAttackEnanble;
public:
	UPlayerAnimInstance();
public:
	 virtual void NativeInitializeAnimation();
	 virtual void NativeUpdateAnimation(float DeltaSeconds);

public:
	void PlayAttackMontage();

	UFUNCTION()
	void AnimNotify_Attack();

	UFUNCTION()
	void AnimNotify_AttackEnable();

	UFUNCTION()
	void AnimNotify_AttackEnd();

};
