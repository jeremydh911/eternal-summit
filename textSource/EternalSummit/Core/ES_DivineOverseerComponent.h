#pragma once

#include "Core/GameStateBase.h"
#include "ES_DivineOverseerComponent.generated.h"

/**
 * Divine Oversight Pillar: Server-authoritative moral consequences drive emergent gameplay.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ETERNALSUMMIT_API UES_DivineOverseerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UES_DivineOverseerComponent();

    UFUNCTION(BlueprintCallable, Category = "Divine")
    void InitializeDivineSystems();

    UFUNCTION(BlueprintCallable, Category = "Divine")
    void ProcessDivineTick(float DeltaTime);

    UFUNCTION(BlueprintCallable, Category = "Divine")
    void TriggerDivineEvent(E_DivineEventType Type);

    UPROPERTY(BlueprintAssignable, Category = "Divine")
    FOnDivineEventChanged OnDivineEventBroadcast;

protected:
    UPROPERTY(EditAnywhere, Category = "Divine Settings")
    float Threshold_DivineIntervention = 75.0f;

    UPROPERTY(EditAnywhere, Category = "Divine Settings")
    float Threshold_Blessing = 25.0f;

    float CurrentEvilScore;

    void ParseDivineEvents(TSharedPtr<FJsonObject> JsonObject);

    // Reference to Codex Manager (should be assigned via GameState or Dependency Injection)
    class UES_CodexManager* CodexManager;
};

UENUM(BlueprintType)
class E_DivineEventType : uint8
{
    enum class E_Smite : uint8 { Smite, Blessing, Chaos };
};