#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DivineOverseerComponent.generated.h"

USTRUCT(BlueprintType)
struct FDivineEventData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Probability;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Effect;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ADivineOverseerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    ADivineOverseerComponent();

    UFUNCTION(BlueprintCallable, Category = "Divine")
    void UpdateEvilScore(float DeltaScore);

    UFUNCTION(BlueprintCallable, Category = "Divine")
    void TriggerDivineEvent(FString EventType);

    UFUNCTION(BlueprintCallable, Category = "Divine")
    void InitializeFromConfig(float InThreshold, float InDecay, float InDisasterProb);

protected:
    UPROPERTY(VisibleAnywhere, Category = "Divine")
    float CurrentEvilScore;

    UPROPERTY(VisibleAnywhere, Category = "Divine")
    float Threshold;

    UPROPERTY(VisibleAnywhere, Category = "Divine")
    float EvilDecayPerDay;

    UPROPERTY(VisibleAnywhere, Category = "Divine")
    float DisasterProbability;

    UPROPERTY(VisibleAnywhere, Category = "Divine")
    TArray<FDivineEventData> DivineEvents;

};