// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/PlayerAnimInstance.h"
#include "Character/MainCharacter.h"

void UPlayerAnimInstance::NativeInitializeAnimation()
{
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	AMainCharacter* OwnerPawn = Cast<AMainCharacter>(TryGetPawnOwner());
	if (IsValid(OwnerPawn))
	{
		UCharacterMovementComponent* Movement = OwnerPawn->GetCharacterMovement();
		if (IsValid(Movement))
		{
			mMoveSpeed = Movement->Velocity.Length();
			
			mMoveSpeed /= Movement->MaxWalkSpeed;

		}
	}
}
