#include "Core/ES_MountainProceduralManager.h"

UES_MountainProceduralManager::UES_MountainProceduralManager()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UES_MountainProceduralManager::InitializeMountainSystem()
{
    CurrentMountainHeights.Empty();
    for (int32 i = 0; i < MountainCountStart; ++i)
    {
        // Start mountains at a base height (e.g., 10% of max)
        CurrentMountainHeights.Add(MaxMountainHeight * 0.1f);
    }
}

void UES_MountainProceduralManager::GrowMountain(int32 MountainIndex, float GrowthAmount)
{
    if (CurrentMountainHeights.IsValidIndex(MountainIndex))
    {
        float NewHeight = FMath::Min(CurrentMountainHeights[MountainIndex] + GrowthAmount, MaxMountainHeight);
        CurrentMountainHeights[MountainIndex] = NewHeight;
        UpdateMountainMesh(MountainIndex);
    }
}

float UES_MountainProceduralManager::GetMountainHeight(int32 MountainIndex) const
{
    return CurrentMountainHeights.IsValidIndex(MountainIndex) ? CurrentMountainHeights[MountainIndex] : 0.0f;
}

void UES_MountainProceduralManager::UpdateMountainMesh(int32 MountainIndex)
{
    // TODO: Trigger Niagara effects and Procedural Mesh updates
    // This will be linked to the Celestial Architect Pillar visual feedback
}