#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ES_MountainProceduralManager.h"
#include "ES_VanguardCombatManager.h"
#include "ES_EchoesAtmosphereManager.h"
#include "ES_Orchestrator.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ETERNALSUMMIT_API UES_Orchestrator : public UActorComponent
{
	GENERATED_BODY()

public:	
	UES_Orchestrator();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// References to the sub-systems
	UPROPERTY(EditAnywhere, Category = "Systems")
	UES_MountainProceduralManager* MountainManager;

	UPROPERTY(EditAnywhere, Category = "Systems")
	UES_VanguardCombatManager* CombatManager;

	UPROPERTY(EditAnywhere, Category = "Systems")
	UES_EchoesAtmosphereManager* EchoesManager;

private:
	// The central binding function
	UFUNCTION()
	void OnMountainStateChanged(EMountainGrowthState NewState);
};