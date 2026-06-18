// Fill out your copyright notice in the Description page of Project Settings.

#include "Net/UnrealNetwork.h"
#include "LobbyGS.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyPC.h"


void ALobbyGS::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyGS, LeftTime);
}

void ALobbyGS::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ALobbyPC* PC = Cast<ALobbyPC>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PC&& PC->IsLocalPlayerController() && PC->LobbyWidgetObject)
	{
		//PC->LobbyWidgetObject->SetTimerTxt(LeftTime);
	}

}
