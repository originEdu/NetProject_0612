// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "BaseLobbyWidget.h"
#include "Engine/World.h"
#include "LobbyGS.h"

void ALobbyPC::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocalPlayerController())
	{
        if (LobbyWidgetTemplate)
        {
		    LobbyWidgetObject = CreateWidget<UBaseLobbyWidget>(this, LobbyWidgetTemplate);

            if (LobbyWidgetObject)
            {
                LobbyWidgetObject->AddToViewport();

                FInputModeUIOnly InputMode;
                SetInputMode(InputMode);
                bShowMouseCursor = true;

                if (HasAuthority())
                {
                    LobbyWidgetObject->ShowStartButton();
                }
            }
        }
	}
}

void ALobbyPC::Kick()
{
    if (HasAuthority())
    {
        S2C_Kick();
    }
}

void ALobbyPC::S2C_Kick_Implementation()
{
    GEngine->HandleDisconnect(GetWorld() , GetWorld()->GetNetDriver());
}

bool ALobbyPC::C2S_SendMessage_Validate(const FText& Message)
{
    return true;
}

void ALobbyPC::C2S_SendMessage_Implementation(const FText& Message)
{
    ALobbyGS* GS = GetWorld()->GetGameState<ALobbyGS>();
    if (GS)
    {
        GS->Multi_BroadcastMessage(Message);
    }
}

