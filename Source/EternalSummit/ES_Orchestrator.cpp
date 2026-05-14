#include "ES_Orchestrator.h"

UES_Orchestrator::UES_Orchestrator()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UES_Orchestrator::BeginPlay()
{
    Super::BeginPlay();

    if (MountainManager)
    {
        MountainManager->OnMountainStateChanged.AddDynamic(this, &UES_Orchestrator::OnMountainStateChanged);
    }
}

void UES_Orchestrator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UES_Orchestrator::OnMountainStateChanged(EMountainGrowthState NewState)
{
    // Orchestrate system responses to mountain evolution
    if (EchoesManager)
    {
        // Example: Change atmosphere based on mountain state
        // EchoesManager->UpdateAtmosphereForState(NewState);
    }

    if (CombatManager)
    {
        // Example: Adjust combat difficulty or spawn rates
        // CombatManager->AdjustDifficultyForState(NewState);
    }
}