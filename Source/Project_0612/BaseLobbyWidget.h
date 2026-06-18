// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseLobbyWidget.generated.h"

class UButton;
class UEditableTextBox;
class UTextBlock;
class UScrollBox;
class UWidgetAnimation;

/**
 * 
 */
UCLASS()
class PROJECT_0612_API UBaseLobbyWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
	TObjectPtr<UButton> StartBtn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidgetOptional))
	TObjectPtr<UButton> SendBtn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
	TObjectPtr<UTextBlock> TimerTxt;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
	TObjectPtr<UTextBlock> UserCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
	TObjectPtr<UScrollBox> ChatBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
	TObjectPtr<UEditableTextBox> InputTxt;
	
	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void PressStart();

	UFUNCTION()
	void PressSend();

	UFUNCTION()
	void PressChatTextEnter(const FText& Text, ETextCommit::Type CommitMethod);
	
	UFUNCTION()
	void ProcessTextChange(const FText& Text);

	UFUNCTION(BlueprintCallable)
	void SetTimerTxt(int32 InTime);

	UFUNCTION(BlueprintCallable)
	void SetUserCount(int32 InCount);

	UFUNCTION(BlueprintCallable)
	void ShowStartButton();

	UPROPERTY(Transient,meta = (BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> ShowButtonAnim;
};
