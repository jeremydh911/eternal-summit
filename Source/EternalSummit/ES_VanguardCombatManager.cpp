#include "ES_VanguardCombatManager.h"

UES_VanguardCombatManager::UES_VanguardCombatManager()
{
    PrimaryComponentTick.bCanEverTick = true;
    CurrentDifficultyMultiplier = 1.0f;
}

void UES_VanguardCombatManager::BeginPlay()
{
    Super::BeginPlay();

    if (MountainManager)
    {
        // Bind to the mountain state change delegate
        MountainManager->OnMountainStateChanged.AddDynamic(this, &UES_VanguardCombatManager::UpdateDifficultyForState);
        
        // Sync initial state
        UpdateDifficultyForState(MountainManager->GetCurrentState());
    }
}

void UES_VanguardCombatManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UES_VanguardCombatManager::UpdateDifficultyForState(EMountainGrowthState NewState)
{
    switch (NewState)
    {
        case EMountainGrowthState::Seed:
            CurrentDifficultyMultiplier = 1.0f;
            break;
        case EMountainGrowthState::Growing:
            CurrentDifficultyMultiplier = 1.5f;
            break;
        case EMountainGrowthState::Peak:
            CurrentDifficultyMultiplier = 2.5f;
            break;
        case EMountainGrowthState::Corrupted:
            CurrentDifficultyMultiplier = 4.0f; // Extreme difficulty
            break;
        case EMountainGrowthState::Blessed:
            CurrentDifficultyMultiplier = 0.8f; // Easier difficulty
            break;
        default:
            CurrentDifficultyMultiplier = 1.0f;
            break;
    }

    UE_LOG(LogTemp, Log, TEXT("Combat Manager: Difficulty updated to %f based on Mountain State."), CurrentDifficultyMultiplier);
    
    // Broadcast the change to any listeners
    OnCombatDifficultyChanged.Broadcast(CurrentDifficultyMultiplier);
}