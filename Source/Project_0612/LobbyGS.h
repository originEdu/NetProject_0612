// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LobbyGS.generated.h"

class FLifetimeProperty;
/**
 * 
 */
UCLASS()
class PROJECT_0612_API ALobbyGS : public AGameStateBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int32 LeftTime = 180;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) override;
	
	virtual void Tick(float DeltaSeconds) override;
};
