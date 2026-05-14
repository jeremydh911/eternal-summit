#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DivineOverseerComponent.generated.h"

/**
 * Delegate for divine events
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDivineEventTriggered,
    const FString&, EventID,
    float, Intensity);

/**
 * UES_DivineOverseerComponent
 * 
 * Divine Oversight Pillar: Server-authoritative moral consequences drive emergent gameplay.
 * Responsible for managing and triggering divine events based on world-state (Evil/Blessing scores).
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ETERNALSUMMIT_API UES_DivineOverseerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UES_DivineOverseerComponent();

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    /** Broadcasts when a divine event occurs */
    UPROPERTY(BlueprintAssignable, Category = "Divine")
    FOnDivineEventTriggered OnDivineEventTriggered;

    /** Triggers a new divine event */
    UFUNCTION(BlueprintCallable, Category = "Divine")
    void TriggerDivineEvent(const FString& EventID, float Intensity);

    /** Processes the divine logic loop (Server-side) */
    UFUNCTION(BlueprintCallable, Category = "Divine")
    void ProcessDivineTick(float DeltaTime);

private:
    /** Loads DivineEvents.json and CodexPages.json from Content/Data/ */
    void LoadDivineData();

    UPROPERTY()
    TArray<FString> LoadedDivineEventIDs;

    float CurrentEvilAccumulation; 
};
