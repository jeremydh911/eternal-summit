#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ES_MountainProceduralManager.h"
#include "ES_EchoesSystem.generated.h"

USTRUCT(BlueprintType)
struct FEchoEvent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EchoName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TriggerThreshold = 0.0f; // How much growth/corruption is needed
};

UCLASS( ClassGroup=(Custom), meta=(Blueprintable, BlueprintType) )
class ETERNALSUMMIT_API UES_EchoesSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	UES_EchoesSystem();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Link to the mountain manager
	UPROPERTY(EditAnywhere, Category = "Eternal Summit|Links")
	UES_MountainProceduralManager* MountainManager;

	// List of historical echoes to trigger based on state
	UPROPERTY(EditAnywhere, Category = "Eternal Summit|Narrative")
	TArray<FEchoEvent> PotentialEchoes;

private:
	UFUNCTION()
	void OnMountainStateChanged(EMountainGrowthState NewState);

	void TriggerEcho(const FEchoEvent& Echo);

	bool bHasTriggeredAllEchoes;
};