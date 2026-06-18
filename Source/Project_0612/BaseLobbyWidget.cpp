// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLobbyWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Components/ScrollBox.h"
#include "Animation/WidgetAnimation.h"
#include "LobbyPC.h"

void UBaseLobbyWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	StartBtn->OnClicked.AddDynamic(this, &UBaseLobbyWidget::PressStart);
	if (SendBtn)
	{
		SendBtn->OnClicked.AddDynamic(this, &UBaseLobbyWidget::PressSend);
	}
	InputTxt->OnTextCommitted.AddDynamic(this, &UBaseLobbyWidget::PressChatTextEnter);
	InputTxt->OnTextChanged.AddDynamic(this, &UBaseLobbyWidget::ProcessTextChange);
}

void UBaseLobbyWidget::PressStart()
{
}

void UBaseLobbyWidget::PressSend()
{
	ALobbyPC* PC = Cast<ALobbyPC>(GetOwningPlayer());
	if (PC)
	{
		PC->C2S_SendMessage(InputTxt->GetText());
		InputTxt->SetText(FText::GetEmpty());
	}
}

void UBaseLobbyWidget::PressChatTextEnter(const FText& Text, ETextCommit::Type CommitMethod)
{
	ALobbyPC* PC = Cast<ALobbyPC>(GetOwningPlayer());
	if (!PC) 
		return;

	switch (CommitMethod)
	{
	case ETextCommit::OnEnter:
		PC->C2S_SendMessage(Text);
		InputTxt->SetText(FText::GetEmpty());
		break;
	}
}

void UBaseLobbyWidget::ProcessTextChange(const FText& Text)
{
}

void UBaseLobbyWidget::SetTimerTxt(int32 InTime)
{
	FString Temp = FString::Printf(TEXT("%d 초"), InTime);
	TimerTxt->SetText(FText::FromString(Temp));
}

void UBaseLobbyWidget::SetUserCount(int32 InCount)
{
	FString Temp = FString::Printf(TEXT("%d 명"), InCount);
	UserCount->SetText(FText::FromString(Temp));
}

void UBaseLobbyWidget::ShowStartButton()
{
	StartBtn->SetVisibility(ESlateVisibility::Visible);
	PlayAnimation(ShowButtonAnim);
}
