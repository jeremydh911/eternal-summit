#pragma once

#include "Core/GameStateBase.h"
#include "ES_CodexManager.generated.h"

/**
 * Codex Discovery Pillar: Players unlock ancient knowledge through divine favor and achievement.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ETERNALSUMMIT_API UES_CodexManager : public UActorComponent
{
    GENERATED_BODY()

public:
    UES_CodexManager();

    UFUNCTION(BlueprintCallable, Category = "Codex")
    void InitializeCodexSystems();

    UFUNCTION(BlueprintCallable, Category = "Codex")
    void GrantRandomPage();

    UFUNCTION(BlueprintPure, Category = "Codex")
    bool IsPageUnlocked(FName PageID) const;

    UPROPERTY(BlueprintAssignable, Category = "Codex")
    FOnCodexPageUnlocked OnCodexPageUnlocked;

protected:
    UPROPERTY(EditAnywhere, Category = "Codex Settings")
    FString CodexDataPath = "Data/CodexPages.json";

    void LoadCodexData();

    // Internal map of unlocked pages
    UPROPERTY()
    TMap<FName, bool> UnlockedPages;
};
