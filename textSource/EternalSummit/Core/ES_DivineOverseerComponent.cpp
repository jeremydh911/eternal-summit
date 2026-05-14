#include "Core/ES_DivineOverseerComponent.h"
#include "Codex/ES_CodexManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

/**
 * Divine Oversight Pillar: Server-authoritative moral consequences drive emergent gameplay.
 * This component bridges Divine Events with Codex discovery.
 */
void UES_DivineOverseerComponent::InitializeDivineSystems()
{
    // Load Divine Events
    FString EventPath = FPaths::ProjectContentDir() + TEXT("Data/DivineEvents.json");
    FString JsonString;
    if (FFileHelper::LoadFileToString(JsonString, *EventPath))
    {
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
        TSharedPtr<FJsonObject> JsonObject;
        if (FJsonSerializer::Deserialize(Reader, JsonObject))
        {
            // Parse and populate internal event table
            ParseDivineEvents(JsonObject);
        }
    }

    // Load Codex Data
    FString CodexPath = FPaths::ProjectContentDir() + TEXT("Data/CodexPages.json");
    FString CodexString;
    if (FFileHelper::LoadFileToString(CodexString, *CodexPath))
    {
        // Logic to link Codex to Divine Blessings
    }
}

void UES_DivineOverseerComponent::ProcessDivineTick(float DeltaTime)
{
    // Calculate Evil Score drift and trigger events based on threshold
    float CurrentEvil = GetCurrentEvilScore();
    
    if (CurrentEvil > Threshold_DivineIntervention)
    {
        TriggerDivineEvent(E_DivineEventType::Smite);
    }
    else if (CurrentEvil < Threshold_Blessing)
    {
        TriggerDivineEvent(E_DivineEventType::Blessing);
    }
}

void UES_DivineOverseerComponent::TriggerDivineEvent(E_DivineEventType Type)
{
    // Broadcast to GAS, Niagara, and Codex
    if (Type == E_DivineEventType::Blessing)
    {
        // Sprint 1: Link Blessing to Codex Discovery
        if (CodexManager) 
        {
            CodexManager->GrantRandomPage();
        }
    }
    
    OnDivineEventBroadcast.Broadcast(Type);
}