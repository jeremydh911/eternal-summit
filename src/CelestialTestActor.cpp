#include "CelestialTestActor.h"

ACelestialTestActor::ACelestialTestActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// Initialize components
	OverseerComponent = CreateDefaultSubobject<UES_DivineOverseerComponent>(TEXT("OverseerComponent"));
	MountainManager = CreateDefaultSubobject<UES_MountainProceduralManager>(TEXT("MountainManager"));
}

void ACelestialTestActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("CelestialTestActor: Test Actor Ready."));
}

void ACelestialTestActor::SimulateEvilAction(float Amount)
{
	if (OverseerComponent)
	{
		UE_LOG(LogTemp, Log, TEXT("CelestialTestActor: Simulating evil action of magnitude %f"), Amount);
		OverseerComponent->IncrementEvilScore(Amount);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("CelestialTestActor: OverseerComponent is null! Cannot simulate action."));
	}
}