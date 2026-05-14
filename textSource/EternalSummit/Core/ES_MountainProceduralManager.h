#pragma once

#include "Core/GameStateBase.h"
#include "Components/ProceduralMeshComponent.h"
#include "ES_MountainProceduralManager.generated.h"

/**
 * Celestial Architect Pillar: Procedural mountain growth drives the verticality and strategic value of the map.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ETERNALSUMMIT_API UES_MountainProceduralManager : public USceneComponent
{
    GENERATED_BODY()

public:
    UES_MountainProceduralManager();

    UFUNCTION(BlueprintCallable, Category = "Mountain")
    void InitializeMountainSystem();

    UFUNCTION(BlueprintCallable, Category = "Mountain")
    void GrowMountain(int32 MountainIndex, float GrowthAmount);

    UFUNCTION(BlueprintPure, Category = "Mountain")
    float GetMountainHeight(int32 MountainIndex) const;

protected:
    UPROPERTY(EditAnywhere, Category = "Mountain Settings")
    int32 MountainCountStart = 15;

    UPROPERTY(EditAnywhere, Category = "Mountain Settings")
    float MaxMountainHeight = 5000.0f;

    // Array to track current height of each mountain
    UPROPERTY()
    TArray<float> CurrentMountainHeights;

    // Logic to trigger Niagara/Mesh updates
    void UpdateMountainMesh(int32 MountainIndex);
};
