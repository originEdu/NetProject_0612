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

};
