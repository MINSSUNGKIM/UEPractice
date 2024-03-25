// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/PlayerAnimInstance.h"
#include "Character/MainCharacter.h"
#include "Character/MainPlayerController.h"

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AMainCharacter* PlayerCharacter = Cast<AMainCharacter>(TryGetPawnOwner());
	if (IsValid(PlayerCharacter))
	{
		UCharacterMovementComponent* Movement = PlayerCharacter->GetCharacterMovement();
		if (IsValid(Movement))
		{
			mMoveSpeed = Movement->Velocity.Length();
			
			mMoveSpeed /= Movement->MaxWalkSpeed;

		}
		//애님인스턴스를 가지고 있는 캐릭터로부터 해당 캐릭터의 플레이어 컨트롤러 받아오기.
		AMainPlayerController* Controller = PlayerCharacter->GetController<AMainPlayerController>();

		if (IsValid(Controller))
		{
			mDir = Controller->GetMoveDir();
		}
	}
}
