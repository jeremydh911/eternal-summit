#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ES_OverseerSystem.h"
#include "ES_TestEnvironment.generated.h"

UCLASS()
class ETERNALSUMMIT_API AES_TestEnvironment : public AActor
{
    GENERATED_BODY()
    
public:    
    AES_TestEnvironment();

protected:
    virtual void BeginPlay() override;

private:
    /** Timer handle for the simulation loop */
    FTimerHandle SimulationTimerHandle;

public:    
    /** Reference to the Overseer System on this actor */
    UPROPERTY(EditAnywhere, Category = "Test")
    UES_OverseerSystem* TestOverseer;

    /** Function to trigger a random action for testing */
    UFUNCTION(BlueprintCallable, Category = "Test")
    void TriggerRandomAction();

    /** Function to trigger a specific action */
    UFUNCTION(BlueprintCallable, Category = "Test")
    void TestSmite();

    UFUNCTION(BlueprintCallable, Category = "Test")
    void TestBless();
};