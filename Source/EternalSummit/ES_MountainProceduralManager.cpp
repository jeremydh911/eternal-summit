#include "ES_MountainProceduralManager.h"
#include "Components/StaticMeshComponent.h"

UES_MountainProceduralManager::UES_MountainProceduralManager()
{
    PrimaryComponentTick.bCanEverTick = true;
    CurrentState = EMountainGrowthState::Seed;
    CurrentHeight = 0.0f;
    CurrentEvilLevel = 0.0f;
    CurrentBlessingLevel = 0.0f;
}

void UES_MountainProceduralManager::BeginPlay()
{
    Super::BeginPlay();
    
    // Automatically find the Static Mesh Component on the owner to allow visual updates
    MountainMesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
}

void UES_MountainProceduralManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    // Simulate growth over time if in Growing state
    if (CurrentState == EMountainGrowthState::Growing && CurrentHeight < GrowthParams.MaxHeight)
    {
        CurrentHeight += GrowthParams.GrowthRate * DeltaTime * 100.0f;
        UpdateVisuals();
    }
}

void UES_MountainProceduralManager::HandleDivineSmite(float Intensity)
{
    UpdateGrowthFromEvilScore(Intensity);
}

void UES_MountainProceduralManager::HandleDivineBlessing(float Intensity)
{
    CurrentBlessingLevel += Intensity;
    if (CurrentBlessingLevel > 0.8f)
    {
        TransitionToState(EMountainGrowthState::Blessed);
    }
}

void UES_MountainProceduralManager::UpdateGrowthFromEvilScore(float EvilScore)
{
    CurrentEvilLevel = EvilScore;
    if (CurrentEvilLevel > GrowthParams.CorruptionThreshold)
    {
        TransitionToState(EMountainGrowthState::Corrupted);
    }
}

void UES_MountainProceduralManager::TransitionToState(EMountainGrowthState NewState)
{
    if (CurrentState != NewState)
    {
        CurrentState = NewState;
        OnMountainStateChanged.Broadcast(NewState);
        UpdateVisuals();
    }
}

void UES_MountainProceduralManager::UpdateVisuals()
{
    if (MountainMesh)
    {
        FVector NewScale = FVector::ZeroVector;
        float ScaleFactor = FMath::Clamp(CurrentHeight / GrowthParams.MaxHeight, 0.0f, 1.0f);
        
        NewScale.X = 1.0f;
        NewScale.Y = 1.0f;
        NewScale.Z = ScaleFactor;
        
        MountainMesh->SetRelativeScale3D(NewScale);
    }
}