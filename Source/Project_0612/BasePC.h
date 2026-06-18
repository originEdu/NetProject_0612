// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePC.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_0612_API ABasePC : public APlayerController
{
	GENERATED_BODY()
public:
	ABasePC();
	virtual ~ABasePC();
	virtual void OnPossess(APawn* aPawn) override;

	virtual void BeginPlay() override;
};
