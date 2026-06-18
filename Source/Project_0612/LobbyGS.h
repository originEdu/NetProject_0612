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
	ALobbyGS();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Time", Replicated)
	int32 LeftTime = 180;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UserCount", Replicated)
	int32 CurrentPlayerCount = 0;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
	
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(NetMulticast, Reliable)
	void Multi_BroadcastMessage(const FText& Message);
	void Multi_BroadcastMessage_Implementation(const FText& Message);

};
