#include "ES_EchoesSystem.h"

UES_EchoesSystem::UES_EchoesSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
	bHasTriggeredAllEchoes = false;
}

void UES_EchoesSystem::BeginPlay()
{
	Super::BeginPlay();

	if (MountainManager)
	{
		// Bind to the mountain's state change delegate
		MountainManager->OnMountainStateChanged.AddDynamic(this, &UES_EchoesSystem::OnMountainStateChanged);
		
		// Check initial state
		OnMountainStateChanged(MountainManager->GetCurrentState());
	}
}

void UES_EchoesSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UES_EchoesSystem::OnMountainStateChanged(EMountainGrowthState NewState)
{
	if (bHasTriggeredAllEchoes) return;

	// In a real implementation, we would compare the state or a growth value 
	// against the Thresholds in PotentialEchoes.
	// For now, we iterate and trigger echoes that match the current state logic.
	
	for (const FEchoEvent& Echo : PotentialEchoes)
	{
		// Simplified trigger logic: if an echo exists, we "trigger" it 
		// (In production, this would involve checking specific growth percentages)
		TriggerEcho(Echo);
	}
}

void UES_EchoesSystem::TriggerEcho(const FEchoEvent& Echo)
{
	// This is where we would call into an Audio Manager or VFX Manager
	UE_LOG(LogTemp, Log, TEXT("Eternal Summit Echo Triggered: %s"), *Echo.EchoName);
	
	// For demonstration, if we reach a certain number of echoes, we stop
	if (PotentialEchoes.Num() > 0)
	{
		// bHasTriggeredAllEchoes = true; // Uncomment to prevent repeat triggers in this demo
	}
}