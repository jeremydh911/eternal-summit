#include "AES_MountainActor.h"
#include "Components/StaticMeshComponent.h"

AES_MountainActor::AES_MountainActor()
{
    PrimaryActorTick.bCanEverTick = true;

    RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent = RootSceneComponent;

    MountainManager = CreateDefaultSubobject<UES_MountainProceduralManager>(TEXT("MountainManager"));

    // Create a placeholder mesh component so the manager has something to scale
    UStaticMeshComponent* PlaceholderMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MountainMesh"));
    PlaceholderMesh->SetupAttachment(RootSceneComponent);
}

void AES_MountainActor::BeginPlay()
{
    Super::BeginPlay();
}

void AES_MountainActor::TriggerSmite(float Intensity)
{
    if (MountainManager)
    {
        MountainManager->HandleDivineSmite(Intensity);
    }
}

void AES_MountainActor::TriggerBlessing(float Intensity)
{
    if (MountainManager)
    {
        MountainManager->HandleDivineBlessing(Intensity);
    }
}