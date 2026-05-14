#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ES_MountainProceduralManager.h"
#include "AES_MountainActor.generated.h"

UCLASS()
class ETERNALSUMMIT_API AES_MountainActor : public AActor
{
    GENERATED_BODY()
    
public:
    AES_MountainActor();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Celestial")
    UES_MountainProceduralManager* MountainManager;

    UFUNCTION(BlueprintCallable, Category = "Divine Intervention")
    void TriggerSmite(float Intensity);

    UFUNCTION(BlueprintCallable, Category = "Divine Intervention")
    void TriggerBlessing(float Intensity);

private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    USceneComponent* RootSceneComponent;
};