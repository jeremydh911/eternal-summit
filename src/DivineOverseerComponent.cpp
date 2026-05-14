#include "DivineOverseerComponent.h"

ADivineOverseerComponent::ADivineOverseerComponent()
    : CurrentEvilScore(0.0f)
    , Threshold(100.0f)
    , EvilDecayPerDay(5.0f)
    , DisasterProbability(0.05f)
{
}

void ADivineOverseerComponent::InitializeFromConfig(float InThreshold, float InDecay, float InDisasterProb)
{
    Threshold = InThreshold;
    EvilDecayPerDay = InDecay;
    DisasterProbability = InDisasterProb;
    UE_LOG(LogTemp, Log, TEXT("Divine System Initialized: Threshold=%f, Decay=%f, Prob=%f"), Threshold, EvilDecayPerDay, DisasterProbability);
}

void ADivineOverseerComponent::UpdateEvilScore(float DeltaScore)
{
    CurrentEvilScore += DeltaScore;
    if (CurrentEvilScore < 0.0f) CurrentEvilScore = 0.0f;

    if (CurrentEvilScore >= Threshold)
    {
        TriggerDivineEvent("ThresholdReached");
    }
}

void ADivineOverseerComponent::TriggerDivineEvent(FString EventType)
{
    if (EventType == "ThresholdReached")
    {
        UE_LOG(LogTemp, Warning, TEXT("THRESHOLD REACHED: Triggering divine wrath!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Divine Event Triggered: %s"), *EventType);
    }
}