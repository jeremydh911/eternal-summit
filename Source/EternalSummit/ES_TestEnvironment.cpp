#include "ES_TestEnvironment.h"
#include "AES_MountainActor.h"
#include "Kismet/GameplayStatics.h"

AES_TestEnvironment::AES_TestEnvironment()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AES_TestEnvironment::BeginPlay()
{
    Super::BeginPlay();
}

void AES_TestEnvironment::TriggerRandomAction()
{
    float RandomVal = FMath::FRandRange(0.5f, 1.5f);
    if (FMath::RandBool())
    {
        TestSmite();
    }
    else
    {
        TestBless();
    }
}

void AES_TestEnvironment::TestSmite()
{
    // Find the Mountain Actor in the level to trigger a Smite
    AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), AES_MountainActor::StaticClass());
    if (AES_MountainActor* MountainActor = Cast<AES_MountainActor>(FoundActor))
    {
        MountainActor->TriggerSmite(1.0f);
        UE_LOG(LogTemp, Warning, TEXT("Test Environment: Triggered Smite!"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Test Environment: No AES_MountainActor found in level!"));
    }
}

void AES_TestEnvironment::TestBless()
{
    // Find the Mountain Actor in the level to trigger a Blessing
    AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), AES_MountainActor::StaticClass());
    if (AES_MountainActor* MountainActor = Cast<AES_MountainActor>(FoundActor))
    {
        MountainActor->TriggerBlessing(1.0f);
        UE_LOG(LogTemp, Warning, TEXT("Test Environment: Triggered Blessing!"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Test Environment: No AES_MountainActor found in level!"));
    }
}