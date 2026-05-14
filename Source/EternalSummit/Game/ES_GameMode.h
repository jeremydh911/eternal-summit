#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "../DivineOverseerComponent.h"
#include "ES_GameMode.generated.h"

UCLASS()
class ETERNALSUMMIT_API AES_GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AES_GameMode();

protected:
    virtual void BeginPlay() override;

    // The interval at which divine events are processed
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine Settings")
    float DivineTickInterval;

    // The actual timer handle
    FTimerHandle DivineTickTimerHandle;

    // Reference to the component (usually attached to the GameState or a dedicated Actor)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine Settings")
    TSubclassOf<UES_DivineOverseerComponent> DivineOverseerClass;

private:
    void ExecuteDivineTick();
};
