// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGM.h"
#include "BasePC.h"
#include "BaseCharacter.h"
#include "BaseHUD.h"

ATestGM::ATestGM()
{
	PlayerControllerClass = ABasePC::StaticClass();
	DefaultPawnClass = ABaseCharacter::StaticClass();
	HUDClass = ABaseHUD::StaticClass();
}

void ATestGM::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId,ErrorMessage);
}

APlayerController* ATestGM::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	APlayerController* NewPlayerController = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
	return NewPlayerController;
}

void ATestGM::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void ATestGM::StartPlay()
{
	Super::StartPlay();
}

void ATestGM::BeginPlay()
{
	Super::BeginPlay();
}
