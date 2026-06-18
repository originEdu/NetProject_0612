// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePC.h"
#include "Kismet/KismetSystemLibrary.h"

ABasePC::ABasePC()
{
}

ABasePC::~ABasePC()
{
}

void ABasePC::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);
}

void ABasePC::BeginPlay()
{
    Super::BeginPlay();

    // 1. 내가 서버(호스트)인지 검사하는 가장 흔한 방법
    if (GetLocalRole() == ROLE_Authority) // 혹은 간단히 HasAuthority()
    {
        // 서버에서만 실행되어야 하는 중요한 로직 (데미지 계산, 아이템 획득 등)
    }

    // 2. 내가 직접 조종하는 로컬 플레이어 캐릭터인지 검사
    if (GetLocalRole() == ROLE_AutonomousProxy && GetRemoteRole() == ROLE_Authority)
    {
        // 로컬 클라이언트에서만 실행되는 UI 연출, 클라이언트 측 예측 입력 등
    }

    // 3. 다른 사람이 조종하는 캐릭터인지 검사
    if (GetLocalRole() == ROLE_SimulatedProxy && GetRemoteRole() == ROLE_Authority)
    {
        // 서버에서 받은 위치값으로 부드럽게 보정(Interpolation)하는 비주얼 로직 등
    }
}
