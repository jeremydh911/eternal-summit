#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ES_MountainProceduralManager.h"
#include "ES_OverseerSystem.generated.h"

UENUM(BlueprintType)
enum class EOverseerAction : uint8
{
    Smite      UMETA(DisplayName = "Smite"),
    Bless      UMETA(DisplayName = "Bless"),
    Nurture    UMETA(DisplayName = "Nurture")
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ETERNALSUMMIT_API UES_OverseerSystem : public UActorComponent
{
    GENERATED_BODY()

public:    UES_OverseerSystem();

protected:
    virtual void BeginPlay() override;

public:    
    /** Link the manager to this system */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overseer")
    class UES_MountainProceduralManager* MountainManager;

    /** Triggers a state change in the mountain based on Overseer input */
    UFUNCTION(BlueprintCallable, Category = "Overseer")
    void RequestMountainAction(EOverseerAction Action, float Intensity);

private:
    /** Internal dispatch helpers */
    void ExecuteDivineSmite(float Intensity);
    void ExecuteDivineBlessing(float Intensity);
    void ProcessNurture(float Intensity);
};