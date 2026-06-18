// Fill out your copyright notice in the Description page of Project Settings.

#include "LobbyGS.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyPC.h"
#include "BaseLobbyWidget.h"

ALobbyGS::ALobbyGS()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALobbyGS::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ALobbyGS, LeftTime);
	DOREPLIFETIME(ALobbyGS, CurrentPlayerCount);
}

void ALobbyGS::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ALobbyPC* PC = Cast<ALobbyPC>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PC&& PC->IsLocalPlayerController() && PC->LobbyWidgetObject)
	{
		PC->LobbyWidgetObject->SetTimerTxt(LeftTime);
		PC->LobbyWidgetObject->SetUserCount(CurrentPlayerCount);
	}
}

void ALobbyGS::Multi_BroadcastMessage_Implementation(const FText& Message)
{
	ALobbyPC* PC = Cast<ALobbyPC>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PC)
	{
		if (PC->LobbyWidgetObject)
		{
			PC->LobbyWidgetObject->AddMessage(Message);
		}
	}
}
