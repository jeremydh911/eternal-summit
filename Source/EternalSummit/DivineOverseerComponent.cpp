#include "DivineOverseerComponent.h"
#include "CodexManager.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

/**
 * UES_DivineOverseerComponent
 * 
 * Divine Oversight Pillar: Server-authoritative moral consequences drive emergent gameplay.
 */

UES_DivineOverseerComponent::UES_DivineOverseerComponent()
    : CurrentEvilAccumulation(0.0f)
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UES_DivineOverseerComponent::BeginPlay()
{
    Super::BeginPlay();
    LoadDivineData();
}

void UES_DivineOverseerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (GetWorld()->IsNetMode(NM_DedicatedServer) || GetWorld()->GetNetMode() == NM_ListenServer)
    {
        ProcessDivineTick(DeltaTime);
    }
}

void UES_DivineOverseerComponent::LoadDivineData()
{
    // Implementation for loading JSON data from Content/Data/DivineEvents.json
    // Placeholder for current sprint
}

void UES_DivineOverseerComponent::ProcessDivineTick(float DeltaTime)
{
    // Accumulate 'Evil' or 'Chaos' based on world state (Logic to be expanded)
    // If threshold met, trigger TriggerDivineEvent()
}

void UES_DivineOverseerComponent::TriggerDivineEvent(const FString& EventID, float Intensity)
{
    // Notify listeners (CodexManager, etc.)
    OnDivineEventTriggered.Broadcast(EventID, Intensity);

    AActor* Owner = GetOwner();
    if (Owner)
    {
        UES_CodexManager* CodexManager = Owner->FindComponentByClass<UES_CodexManager>();
        if (CodexManager)
        {
            CodexManager->HandleDivineEvent(EventID, Intensity);
        }
        else
        {
            APlayerController* PC = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());
            if (PC)
            {
                UES_CodexManager* FoundCodex = PC->FindComponentByClass<UES_CodexManager>();
                if (FoundCodex)
                {
                    FoundCodex->HandleDivineEvent(EventID, Intensity);
                }
            }
        }
    }
}