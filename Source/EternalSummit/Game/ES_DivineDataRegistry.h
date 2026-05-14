#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ES_DivineDataRegistry.generated.h"

USTRUCT(BlueprintType)
struct FDivineEventEffect
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FString TargetClass;

    UPROPERTY(BlueprintReadOnly)
    float Magnitude = 0.0f;

    UPROPERTY(BlueprintReadOnly)
    float HealAmount = 0.0f;
};

USTRUCT(BlueprintType)
struct FDivineEventData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FString EventID;

    UPROPERTY(BlueprintReadOnly)
    FString Type; // e.g., "Punishment" or "Reward"

    UPROPERTY(BlueprintReadOnly)
    float Threshold = 0.0f;

    UPROPERTY(BlueprintReadOnly)
    float Probability = 0.0f;

    UPROPERTY(BlueprintReadOnly)
    FDivineEventEffect Effect;
};

/**
 * ES_DivineDataRegistry
 * Acts as the bridge between the JSON data and the C++ runtime.
 */
UCLASS()
class ETERNALSUMMIT_API UES_DivineDataRegistry : public UObject
{
    GENERATED_BODY()

public:
    // Loads the JSON file from the Content directory
    UFUNCTION(BlueprintCallable, Category = "Divine Engine")
    void LoadDivineData(FString FilePath);

    // Returns all loaded events
    UFUNCTION(BlueprintCallable, Category = "Divine Engine")
    TArray<FDivineEventData> GetLoadedEvents() const { return LoadedEvents; }

private:
    UPROPERTY()
    TArray<FDivineEventData> LoadedEvents;
};
