#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ES_MountainProceduralManager.generated.h"

/**
 * ES_MountainProceduralManager
 * Handles procedural mesh growth stages and divine interaction for mountains.
 * Part of the Celestial Architect sprint.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ETERNALSUMMIT_API UES_MountainProceduralManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UES_MountainProceduralManager();

protected:
	virtual void BeginPlay() override;

public:	
	// Triggers the next growth stage based on Divine Blessings or Evil levels
	UFUNCTION(BlueprintCallable, Category = "Celestial Architect")
	void TriggerGrowthStage(float Magnitude);

	// Updates the procedural mesh geometry
	UFUNCTION(BlueprintCallable, Category = "Celestial Architect")
	void UpdateMountainVisuals();

private:
	UPROPERTY(EditAnywhere, Category = "Mountain Data")
	TArray<float> GrowthStages;

	UPROPERTY(EditAnywhere, Category = "Mountain Data")
	float CurrentGrowthLevel;

	// Internal logic for mesh deformation/scaling
	void ApplyProceduralDeformation(float ScaleFactor);
};