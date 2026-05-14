#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ES_DivineOverseerComponent.h"
#include "ES_MountainProceduralManager.h"
#include "CelestialTestActor.generated.h"

/**
 * ACelestialTestActor
 * A test actor used to verify the interaction between the Overseer and the Mountain Manager.
 */
UCLASS()
class ETERNALSUMMIT_API ACelestialTestActor : public AActor
{
	GENERATED_BODY()

public:
	ACelestialTestActor();

protected:
	virtual void BeginPlay() override;

public:
	// Component to monitor player behavior
	UPROPERTY(VisibleAnywhere, Category = "Test")
	UES_DivineOverseerComponent* OverseerComponent;

	// Component to handle the mountain's physical changes
	UPROPERTY(VisibleAnywhere, Category = "Test")
	UES_MountainProceduralManager* MountainManager;

	// Function to simulate player 