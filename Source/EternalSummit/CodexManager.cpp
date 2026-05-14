#include "CodexManager.h"
#include "Logging/LogMacros.h"

/**
 * UES_CodexManager
 * 
 * Divine-Codex Unity Pillar: The Codex is a living document that reacts to divine intervention.
 */

UES_CodexManager::UES_CodexManager()
    : DivineInterventionCount(0)
{
}

void UES_CodexManager::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Log, TEXT("CodexManager Initialized."));
}

void UES_CodexManager::HandleDivineEvent(const FString& EventID, float Intensity)
{
    DivineInterventionCount++;
    
    UE_LOG(LogTemp, Warning, TEXT("Divine Event Received: %s (Intensity: %f). Total Interventions: %d"), *EventID, Intensity, DivineInterventionCount);

    // Logic to mutate existing lore or add new lore based on event intensity
    FString LoreUpdate = FString::Printf(TEXT("The world was shaken by %s. The heavens wept with intensity %f."), *EventID, Intensity);
    
    AddCodexPage(EventID + "_Lore", LoreUpdate);
}

void UES_CodexManager::AddCodexPage(const FString& PageID, const FString& Content)
{
    CodexEntries.Add(PageID, Content);
    UE_LOG(LogTemp, Log, TEXT("New Codex Page Added: %s"), *PageID);
}