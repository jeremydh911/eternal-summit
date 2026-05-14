#pragma once

#include "Engine/DataAsset.h"
#include "ES_MountainGrowthData.generated.h"

USTRUCT(BlueprintType)
struct FMountainStageSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float HeightScale = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float VertexDensity = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float TransitionDuration = 0.0f;
};

UCLASS(BlueprintType)
class ETERNALSUMMIT_API UES_MountainGrowthData : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Growth Stages")
    TArray<FMountainStageSettings> GrowthStages;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Growth Stages")
    float DefaultTransitionSpeed = 1.0f;
};