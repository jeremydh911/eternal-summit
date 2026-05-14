#include "ES_EchoesAtmosphereManager.h"
#include "Kismet/KismetSystemLibrary.h"

UES_EchoesAtmosphereManager::UES_EchoesAtmosphereManager()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentFogDensity = 0.01f;
	CurrentSkyColor = FLinearColor::White;
}

void UES_EchoesAtmosphereManager::BeginPlay()
{
	Super::BeginPlay();
}

void UES_EchoesAtmosphereManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UES_EchoesAtmosphereManager::AdjustAtmosphereForState(EMountainGrowthState NewState)
{
	UE_LOG(LogTemp, Log, TEXT("Echoes Manager: Adjusting atmosphere for state: %d"), (int32)NewState);

	switch (NewState)
	{
	case EMountainGrowthState::Seed:
		CurrentFogDensity = 0.01f;
		CurrentSkyColor = FLinearColor::White;
		break;

	case EMountainGrowthState::Growing:
		CurrentFogDensity = 0.05f;
		CurrentSkyColor = FLinearColor(0.8f, 0.9f, 1.0f); // Light Blue
		break;

	case EMountainGrowthState::Blessed:
		CurrentFogDensity = 0.02f;
		CurrentSkyColor = FLinearColor(1.0f, 0.9f, 0.7f); // Golden
		break;

	case EMountainGrowthState::Corrupted:
		CurrentFogDensity = 0.15f;
		CurrentSkyColor = FLinearColor(0.2f, 0.1f, 0.3f); // Dark Purple/Void
		break;

	default:
		break;
	}

	ApplyVisuals();
}

void UES_EchoesAtmosphereManager::ApplyVisuals()
{
	// In a full implementation, this would interface with ExponentialHeightFog 
	// and SkyAtmosphere components in the level.
	UE_LOG(LogTemp, Log, TEXT("Echoes Manager: Visuals Applied -> Fog: %f, Sky: %s"), CurrentFogDensity, *CurrentSkyColor.ToString());
}