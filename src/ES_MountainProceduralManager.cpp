#include "ES_MountainProceduralManager.h"
#include "Kismet/KismetMathLibrary.h"

UES_MountainProceduralManager::UES_MountainProceduralManager()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentGrowthLevel = 0.0f;
	GrowthStages = { 1.0f, 1.5f, 2.0f, 3.0f, 5.0f }; // Default growth scale steps
}

void UES_MountainProceduralManager::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("ES_MountainProceduralManager Initialized: Ready for Celestial Growth."));
}

void UES_MountainProceduralManager::TriggerGrowthStage(float Magnitude)
{
	// Magnitude represents the strength of the Divine Blessing or Evil Surge
	float NewLevel = CurrentGrowthLevel + (Magnitude * 0.1f);
	
	if (NewLevel > CurrentGrowthLevel)
	{
		CurrentGrowthLevel = NewLevel;
		UpdateMountainVisuals();
		UE_LOG(LogTemp, Log, TEXT("Mountain Growth Triggered! New Level: %f"), CurrentGrowthLevel);
	}
}

void UES_MountainProceduralManager::UpdateMountainVisuals()
{
	// In a full implementation, this would update a ProceduralMeshComponent
	// For now, we simulate the effect via scaling the Actor
	AActor* Owner = GetOwner();
	if (Owner)
	{
		FVector NewScale = FVector(CurrentGrowthLevel, CurrentGrowthLevel, CurrentGrowthLevel);
		Owner->SetActorScale3D(NewScale);
		ApplyProceduralDeformation(CurrentGrowthLevel);
	}
}

void UES_MountainProceduralManager::ApplyProceduralDeformation(float ScaleFactor)
{
	// Placeholder for Niagara VFX integration and mesh vertex manipulation
	// This is where the 'Celestial Architect' magic happens
	UE_LOG(LogTemp, Log, TEXT("Applying Procedural Deformation at Scale: %f"), ScaleFactor);
}