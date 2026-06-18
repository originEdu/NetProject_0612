// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGM.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"
#include "LobbyGS.h"
#include "LobbyPC.h"
#include "Kismet/GameplayStatics.h"
#include "BaseLobbyWidget.h"

void ALobbyGM::SetIncreaseUserCount(bool bIsIncrease)
{
	ALobbyGS* GS = GetGameState<ALobbyGS>();
	if (GS)
	{
		if (bIsIncrease)
		{
			GS->CurrentPlayerCount++;
		}
		else
		{
			GS->CurrentPlayerCount--;
		}
	}
}


void ALobbyGM::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);
	if (NewPlayer)
	{
		SetIncreaseUserCount(true);
	}
}

void ALobbyGM::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	if (Exiting)
	{
		ALobbyGS* GS = GetGameState<ALobbyGS>();
		if (GS)
		{
			//GS->CurrentPlayerCount = GetNumPlayers();
			SetIncreaseUserCount(false);
		}
	}
}

void ALobbyGM::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(
		LeftTimerHandle,
		[&]()
		{
			ALobbyGS* GS = GetGameState<ALobbyGS>();
			if (GS)
			{
				GS->LeftTime--; //function();
			}
		},
		1,
		true
	);
}

void ALobbyGM::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(LeftTimerHandle);
	Super::EndPlay(EndPlayReason);
}


