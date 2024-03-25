// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Input/BasicInputDataConfig.h"


UBasicInputDataConfig::UBasicInputDataConfig()

	{
		{
			static ConstructorHelpers::FObjectFinder<UInputMappingContext> Asset
			{ TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/IMC_Main.IMC_Main'") };
			if (Asset.Succeeded())
			{
				DefaultContext = Asset.Object;
			}
		}
		{
			static ConstructorHelpers::FObjectFinder<UInputAction> Asset
			{ TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Move.IA_Move'") };
			if (Asset.Succeeded())
			{
				Move = Asset.Object;
			}
		}
	}
