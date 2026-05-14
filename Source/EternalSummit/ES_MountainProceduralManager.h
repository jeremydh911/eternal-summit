#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ES_MountainProceduralManager.generated.h"

/**
 * ES_MountainProceduralManager
 * Pillar: Celestial Architect - Manages the physical growth and divine response of the mountains.
 * This component handles procedural mesh deformation/scaling and reacts to Divine Events.
 */

UENUM(BlueprintType)
enum class EMountainGrowthState : uint8
{
    Seed,
    Growing,
    Peak,
    Corrupted, // Result of high Evil Score
    Blessed    // Result of high Blessing Score
};

USTRUCT(BlueprintType)
struct FMountainGrowthParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float GrowthRate = 0.1f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxHeight = 500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CorruptionThreshold = 0.7f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMountainStateChanged, EMountainGrowthState, NewState);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ETERNALSUMMIT_API UES_MountainProceduralManager : public UActorComponent
{
    GENERATED_BODY()

public:
    UES_MountainProceduralManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // --- Divine Interaction Interface ---

    /** Triggers a visual and structural response to a Divine Smite */
    UFUNCTION(BlueprintCallable, Category = "Divine Interaction")
    void HandleDivineSmite(float Intensity);

    /** Triggers a visual and structural response to a Divine Blessing */
    UFUNCTION(BlueprintCallable, Category = "Divine Interaction")
    void HandleDivineBlessing(float Intensity);

    /** Responds to the Evil Score signal from the Overseer */
    UFUNCTION(BlueprintCallable, Category = "Divine Interaction")
    void UpdateGrowthFromEvilScore(float EvilScore);

    // --- Getters/Setters ---

    UFUNCTION(BlueprintCallable, Category = "Mountain State")
    EMountainGrowthState GetCurrentState() const { return CurrentState; }

    UPROPERTY(BlueprintAssignable, Category = "Mountain Events")
    FOnMountainStateChanged OnMountainStateChanged;

private:
    void UpdateVisuals();
    void TransitionToState(EMountainGrowthState NewState);

    UPROPERTY(EditAnywhere, Category = "Settings")
    FMountainGrowthParams GrowthParams;

    UPROPERTY(VisibleAnywhere, Category = "State")
    EMountainGrowthState CurrentState;

    UPROPERTY(VisibleAnywhere, Category = "State")
    float CurrentHeight;

    UPROPERTY(VisibleAnywhere, Category = "State")
    float CurrentEvilLevel;

    UPROPERTY(VisibleAnywhere, Category = "State")
    float CurrentBlessingLevel;

    // Reference to the mesh to deform/scale
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mountain State", meta = (AllowPrivateAccess = "true"))
    class UStaticMeshComponent* MountainMesh;
};
