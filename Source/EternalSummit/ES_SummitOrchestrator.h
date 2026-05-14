#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ES_MountainProceduralManager.h"
#include "ES_VanguardCombatManager.h"
#include "ES_EchoesSystem.h"
#include "ES_SummitOrchestrator.generated.h"

UCLASS()
class ETERNALSUMMIT_API AES_SummitOrchestrator : public AActor
{
	GENERATED_BODY()
	
public:	
	AES_SummitOrchestrator();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// The primary driving force of the mountain's evolution
	UPROPERTY(EditAnywhere, Category = "Eternal Summit|Core")
	UES_MountainProceduralManager* MountainManager;

	// The combat difficulty controller
	UPROPERTY(EditAnywhere, Category = "Eternal Summit|Core")
	UES_VanguardCombatManager* CombatManager;

	// The narrative/echo controller
	UPROPERTY(EditAnywhere, Category = "Eternal Summit|Core")
	UES_EchoesSystem* EchoesSystem;

private:
	UFUNCTION()
	void OnMountainStateChanged(EMountainGrowthState NewState);
};