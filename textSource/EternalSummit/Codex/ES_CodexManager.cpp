#include "Codex/ES_CodexManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

/**
 * Codex Discovery Pillar: Players unlock ancient knowledge through divine favor and achievement.
 */
UES_CodexManager::UES_CodexManager()
{
    // Constructor initialization
}

void UES_CodexManager::InitializeCodexSystems()
{
    LoadCodexData();
}

void UES_CodexManager::LoadCodexData()
{
    FString FullPath = FPaths::ProjectContentDir() + CodexDataPath;
    FString JsonString;
    if (FFileHelper::LoadFileToString(JsonString, *FullPath))
    {
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
        TSharedPtr<FJsonObject> JsonObject;
        if (FJsonSerializer::Deserialize(Reader, JsonObject))
        {
            // Logic to parse available pages from JSON
        }
    }
}

void UES_CodexManager::GrantRandomPage()
{
    // Implementation for finding an un-unlocked page and unlocking it
    // For demo purposes, we simulate unlocking a page
    FName MockPage = "Page_Divine_Blessing_01";
    UnlockedPages.Add(MockPage, true);
    
    OnCodexPageUnlocked.Broadcast(MockPage);
}

bool UES_CodexManager::IsPageUnlocked(FName PageID) const
{
    if (const TMap<FName, bool>* FoundMap = UnlockedPages.Find(PageID))
    {
        return *FoundMap;
    }
    return false;
}