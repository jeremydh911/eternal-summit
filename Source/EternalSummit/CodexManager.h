#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CodexManager.generated.h"

/**
 * UES_CodexManager
 * 
 * Divine-Codex Unity Pillar: The Codex is a living document that reacts to divine intervention.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ETERNALSUMMIT_API UES_CodexManager : public UActorComponent
{
    GENERATED_BODY()

public:
    UES_CodexManager();

protected:
    virtual void BeginPlay() override;

public:
    /** Called by DivineOverseer when a divine event occurs */
    UFUNCTION(BlueprintCallable, Category = "Codex")
    void HandleDivineEvent(const FString& EventID, float Intensity);

    /** Adds a new page to the Codex */
    UFUNCTION(BlueprintCallable, Category = "Codex")
    void AddCodexPage(const FString& PageID, const FString& Content);

private:
    /** Internal storage for Codex entries */
    UPROPERTY()
    TMap<FString, FString> CodexEntries;

    /** Tracks how many divine events have influenced the world lore */
    int32 DivineInterventionCount;
};