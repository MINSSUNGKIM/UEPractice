// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "UObject/NoExportTypes.h"
#include "BasicInputDataConfig.generated.h"

/**
 * 
 */
UCLASS()
class UBasicInputDataConfig : public UObject
{
	GENERATED_BODY()
public:
	UBasicInputDataConfig();

public:
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* DefaultContext = nullptr;

public:
	UInputAction* Move = nullptr;
	UInputAction* Attack = nullptr;
};

