#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ES_MountainProceduralManager.h"
#include "ES_VanguardCombatManager.generated.h"

// Delegate for combat events
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatDifficultyChanged, float, NewDifficulty);

UCLASS( ClassGroup=(Custom), meta=(Blueprintable, BlueprintType) )
class ETERNALSUMMIT_API UES_VanguardCombatManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	UES_VanguardCombatManager();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Link to the mountain manager to listen for state changes
	UPROPERTY(EditAnywhere, Category = "Eternal Summit|Links")
	UES_MountainProceduralManager* MountainManager;

	// Difficulty multiplier based on mountain corruption/blessing
	UPROPERTY(BlueprintReadOnly, Category = "Eternal Summit|Combat")
	float CurrentDifficultyMultiplier;

	UPROPERTY(BlueprintAssignable, Category = "Eternal Summit|Combat")
	FOnCombatDifficultyChanged OnCombatDifficultyChanged;

	// Updates difficulty based on the current mountain state
	UFUNCTION(BlueprintCallable, Category = "Eternal Summit|Combat")
	void UpdateDifficultyForState(EMountainGrowthState NewState);
};