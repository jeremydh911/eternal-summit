#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ES_MountainProceduralManager.h"
#include "ES_DivineOverseerComponent.generated.h"

/**
 * ES_DivineOverseerComponent
 * 
 * WHY: Divine Oversight Pillar
 * Responsibility: Tracks "Evil Score" through player actions and triggers 
 * celestial events (Disasters/Blessings) to maintain game balance and tension.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ETERNALSUMMIT_API UES_DivineOverseerComponent : public UActorComponent
{
	GENERATED_BODY()

public:\	
	UES_DivineOverseerComponent();

protected:
	virtual void BeginPlay() override;

	// --- Divine Oversight Mechanics ---

	/** Current aggregate Evil Score for the session/server */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine Oversight|Metrics")
	float CurrentEvilScore;

	/** Threshold for triggering a Disaster event */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine Oversight|Settings")
	float DisasterThreshold;

	/** 
	 * Updates the evil score based on player actions (e.g., raiding, hoarding).
	 * Must be called via server-authoritative logic.
	 */
	UFUNCTION(BlueprintCallable, Category = "Divine Oversight|Actions")
	void IncrementEvilScore(float Amount);

	/** Triggers a random Divine Event based on current scores */
	UFUNCTION(BlueprintCallable, Category = "Divine Oversight|Actions")
	void TriggerDivineEvent();

private:
	/** Internal state to prevent event spamming */
	bool bEventCooldownActive;

	/** Reference to the Mountain Manager to trigger growth/destruction */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine Oversight|Integration")
	UES_MountainProceduralManager* MountainManager;
};