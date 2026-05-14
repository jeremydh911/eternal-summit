#include "ES_SummitOrchestrator.h"
#include "ES_MountainProceduralManager.h"
#include "ES_VanguardCombatManager.h"

AES_SummitOrchestrator::AES_SummitOrchestrator()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AES_SummitOrchestrator::BeginPlay()
{
    Super::BeginPlay();

    if (MountainManager && CombatManager)
    {
        // Bind to the Mountain Manager's state change delegate
        MountainManager->OnMountainStateChanged.AddDynamic(this, &AES_SummitOrchestrator::OnMountainStateChanged);
        
        UE_LOG(LogTemp, Log, TEXT("Orchestrator: Systems linked and delegates bound."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Orchestrator: Missing MountainManager or CombatManager references!"));
    }
}

void AES_SummitOrchestrator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AES_SummitOrchestrator::OnMountainStateChanged(EMountainGrowthState NewState)
{
    UE_LOG(LogTemp, Log, TEXT("Orchestrator: Detected Mountain State Change. Synchronizing systems..."));

    // 1. Update Combat Difficulty based on the new world state
    if (CombatManager)
    {
        CombatManager->UpdateDifficultyForState(NewState);
    }

    // 2. Potential future integration: Trigger Echoes/Environment changes
    // if (EchoesManager) { EchoesManager->AdjustAtmosphere(NewState); }
}