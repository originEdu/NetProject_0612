// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPC.generated.h"

class UBaseLobbyWidget;
/**
 * 
 */
UCLASS()
class PROJECT_0612_API ALobbyPC : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UBaseLobbyWidget> LobbyWidgetTemplate;

	UPROPERTY()
	UBaseLobbyWidget* LobbyWidgetObject;

	UFUNCTION(BlueprintCallable)
	void Kick();

	//Server to Client(UDP) -> 비연결, 신뢰성 보장X) -> Reliable해야 신뢰성 보장됨
	UFUNCTION(Client,Reliable)
	void S2C_Kick();
	void S2C_Kick_Implementation();

	UFUNCTION(Server, Reliable, WithValidation)
	void C2S_SendMessage(const FText& Message);
	bool C2S_SendMessage_Validate(const FText& Message);
	void C2S_SendMessage_Implementation(const FText& Message);
};
