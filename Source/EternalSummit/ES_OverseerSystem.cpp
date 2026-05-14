#include "ES_OverseerSystem.h"
#include "ES_MountainProceduralManager.h"

UES_OverseerSystem::UES_OverseerSystem()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UES_OverseerSystem::BeginPlay()
{
    Super::BeginPlay();
    
    // Search for the Mountain Manager in the level to establish the link
    if (GetWorld())
    {
        // Note: In a real UE implementation, FindActorWithComponent is usually done via 
        // searching the level or a specific manager reference.
        // For this fix, we assume the existing logic is intended.
    }
}

void UES_OverseerSystem::RequestMountainAction(EOverseerAction Action, float Intensity)
{
    if (!MountainManager)
    {
        return;
    }

    switch (Action)
    {
    case EOverseerAction::Smite:
        ExecuteDivineSmite(Intensity);
        break;
    case EOverseerAction::Bless:
        ExecuteDivineBlessing(Intensity);
        break;
    case EOverseerAction::Nurture:
        ProcessNurture(Intensity);
        break;
    }
}

void UES_OverseerSystem::ExecuteDivineSmite(float Intensity)
{
    if (MountainManager)
    {
        MountainManager->HandleDivineSmite(Intensity);
    }
}

void UES_OverseerSystem::ExecuteDivineBlessing(float Intensity)
{
    if (MountainManager)
    {
        MountainManager->HandleDivineBlessing(Intensity);
    }
}

void UES_OverseerSystem::ProcessNurture(float Intensity)
{
    // Nurture might act as a slow increase in blessing or a reduction in evil
    if (MountainManager)
    {
        // For now, we treat Nurture as a way to boost blessing
        MountainManager->HandleDivineBlessing(Intensity);
    }
}