// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "BaseLobbyWidget.h"

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
