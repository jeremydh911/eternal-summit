#include "ES_DivineOverseerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ES_MountainProceduralManager.h"

UES_DivineOverseerComponent::UES_DivineOverseerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentEvilScore = 0.0f;
	DisasterThreshold = 100.0f;
	bEventCooldownActive = false;
	MountainManager = nullptr;
}

void UES_DivineOverseerComponent::BeginPlay()
{
	Super::BeginPlay();

	// Attempt to find the Mountain Manager in the current world
	AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), AUES_MountainProceduralManager::StaticClass());
	if (FoundActor)
	{
		MountainManager = Cast<AUES_MountainProceduralManager>(FoundActor);
		UE_LOG(LogTemp, Log, TEXT("ES_DivineOverseerComponent: Successfully linked to MountainManager."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ES_DivineOverseerComponent: Failed to find MountainManager in level!"));
	}
}

void UES_DivineOverseerComponent::IncrementEvilScore(float Amount)
{
	// Server-authoritative check (simplified for prototype)
	if (GetOwnerRole() < ROLE_Authority)
	{
		return;
	}

	CurrentEvilScore += Amount;

	if (CurrentEvilScore >= DisasterThreshold)
	{
		TriggerDivineEvent();
	}
}

void UES_DivineOverseerComponent::TriggerDivineEvent()
{
	if (bEventCooldownActive)
	{
		return;
	}

	// Logic for triggering celestial events (Disasters/Blessings)
	UE_LOG(LogTemp, Warning, TEXT("ES_DivineOverseerComponent: DISASTER TRIGGERED! High Evil Score detected."));

	bEventCooldownActive = true;

	// Integrate with Mountain Manager to physically alter the world
	if (MountainManager)
	{
		// Trigger a sudden growth stage as a celestial reaction
		MountainManager->TriggerGrowthStage(5.0f);
		UE_LOG(LogTemp, Log, TEXT("ES_DivineOverseerComponent: Mountain growth stage dispatched to Manager."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ES_DivineOverseerComponent: Cannot trigger event - MountainManager is null!"));
	}

	// Reset cooldown logic (Simplified: in a real scenario, use a Timer)
	bEventCooldownActive = false;
	CurrentEvilScore = 0.0f; // Reset score after event
}