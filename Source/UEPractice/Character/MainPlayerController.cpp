// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

#include "Data/Input/BasicInputDataConfig.h"


void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	const UBasicInputDataConfig* BasicInputDataConfig = GetDefault<UBasicInputDataConfig>();
	Subsystem->AddMappingContext(BasicInputDataConfig->DefaultContext, 0);
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	ensure(EnhancedInputComponent);

	const UBasicInputDataConfig* BasicInputDataConfig = GetDefault<UBasicInputDataConfig>();
	EnhancedInputComponent->BindAction(BasicInputDataConfig->Move, ETriggerEvent::Triggered, this, &ThisClass::OnMove);
	}

void AMainPlayerController::OnMove(const FInputActionValue& InputActionValue)
{

	APawn* ControlledPawn = GetPawn();

	const FRotator Rotation = K2_GetActorRotation();
	const FRotator YawRotation = FRotator(0.0, Rotation.Yaw, 0.0);
	const FVector ForwardVector = YawRotation.Vector();
	const FVector RightVector = FRotationMatrix(YawRotation).GetScaledAxis(EAxis::Y);

	// 앞 뒤 이동
	const FVector ActionValue = InputActionValue.Get<FVector>();
	ControlledPawn->AddMovementInput(ForwardVector, ActionValue.Y);
	// 좌 우 이동
	ControlledPawn->AddMovementInput(RightVector, ActionValue.X);

	//이동방향 저장, 먼저 좌우 값, 왼쪽 -1 오른쪽 1, 좌우이동 없을시 0
	mMoveDir = ActionValue.X * 90.f;

	//Actionvalue.Y 는 앞 +1 뒤 -1 이동없을시 0
	//앞으로 이동
	if (ActionValue.Y > 0.f)
	{
		if (ActionValue.X < 0.f)
		{
			mMoveDir = -45.f;
		}
		else if (ActionValue.X > 0.f)
		{
			mMoveDir = 45.f;
		}
	

	}
	//뒤로 이동
	else if (ActionValue.Y<0.f)
	{
		if (ActionValue.X < 0.f)
		{
			mMoveDir = -135.f;
		}
		else if (ActionValue.X > 0.f)
		{
			mMoveDir = 135.f;
		}
		

	}
	//앞뒤이동X
	else
	{
		mMoveDir = 180.f;
	}

}
