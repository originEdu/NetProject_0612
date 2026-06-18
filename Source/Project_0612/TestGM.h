// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestGM.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_0612_API ATestGM : public AGameModeBase
{
	GENERATED_BODY()
public:
	ATestGM();
	
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void StartPlay() override;

	virtual void BeginPlay() override;

};
