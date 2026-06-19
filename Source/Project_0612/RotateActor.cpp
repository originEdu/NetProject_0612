// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateActor.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ARotateActor::ARotateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	SetNetUpdateFrequency(1.0f);
	SetReplicateMovement(false);
}

// Called when the game starts or when spawned
void ARotateActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HasAuthority())
	{
		AddActorLocalRotation(FRotator(0, RotateSpeed* DeltaTime,0));
		ServerRotationYaw = GetActorRotation().Yaw;
	}
	else
	{
		ClientTimeSinceUpdate += DeltaTime; 
		if (ClientTimeLastUpdate < KINDA_SMALL_NUMBER) // 너무 작으면 0으로 인식해서 뒤에 나눗셈에 0으로 나누기라서 터짐
		{
			return;
		}
		float CalculateRotationYaw = ServerRotationYaw + (RotateSpeed * ClientTimeLastUpdate);
		float LerpAlpha = ClientTimeSinceUpdate / ClientTimeLastUpdate;
		float ClientNewYaw = FMath::Lerp(ServerRotationYaw, CalculateRotationYaw, LerpAlpha);
		SetActorRotation(FRotator(0, ClientNewYaw, 0));
	}
	
}

void ARotateActor::OnRep_ServerRotationYaw()
{
	SetActorRotation(FRotator(0, ServerRotationYaw, 0));

	ClientTimeLastUpdate = ClientTimeSinceUpdate;
	ClientTimeSinceUpdate = 0;
}

void ARotateActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ARotateActor, ServerRotationYaw);
}

