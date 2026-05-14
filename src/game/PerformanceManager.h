/**
 * Mobile Optimization & Thermal Guarding Implementation
 * Monitors device performance and scales complexity to prevent throttling.
 */

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DivineEventManager.h"
#include "DivineSystemDataAsset.h"
#include "Components/SceneComponent.h"
#include "DivineEventManager.generated.h"

UCLASS()
class APerformanceManager : public AActor
{
    GENERATED_BODY()

public:    
    APerformanceManager();

    // Thresholds for Thermal Guarding
    UPROPERTY(EditAnywhere, Category = "Performance")
    float CriticalThermalThreshold = 0.85f; // 85% thermal limit

    UPROPERTY(EditAnywhere, Category = "Performance")
    float WarningThermalThreshold = 0.70f;  // 70% thermal limit

protected:
    virtual void Tick(float DeltaTime) override;

    // Scales graphics and logic complexity
    UFUNCTION(BlueprintCallable, Category = "Performance")
    void ApplyThermalThrottling(float CurrentThermalLevel);

private:
    float CurrentSystemLoad;
    bool bIsThrottlingActive;
};
