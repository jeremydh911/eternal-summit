#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ES_MountainProceduralManager.h"
#include "ES_EchoesAtmosphereManager.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ETERNALSUMMIT_API UES_EchoesAtmosphereManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	UES_EchoesAtmosphereManager();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called by the Orchestrator when the world state shifts
	UFUNCTION()
	void AdjustAtmosphereForState(EMountainGrowthState NewState);

private:
	UPROPERTY(EditAnywhere, Category = "Atmosphere")
	float CurrentFogDensity;

	UPROPERTY(EditAnywhere, Category = "Atmosphere")
	FLinearColor CurrentSkyColor;

	void ApplyVisuals();
};