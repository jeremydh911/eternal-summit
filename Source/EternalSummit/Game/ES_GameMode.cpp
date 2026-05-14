#include "ES_GameMode.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

/* 
 * ES_GameMode.cpp
 * Pillar: Server Authority - Orchestrating the rhythm of the Divine.
 */

AES_GameMode::AES_GameMode()
{
    // Default interval: 30 seconds between divine evaluations
    DivineTickInterval = 30.0f;
}

void AES_GameMode::BeginPlay()
{
    Super::BeginPlay();

    // Schedule the Divine Tick loop
    GetWorldTimerManager().SetTimer(
        DivineTickTimerHandle, 
        this, 
        &AES_GameMode::ExecuteDivineTick, 
        DivineTickInterval, 
        true
    );

    UE_LOG(LogTemp, Log, TEXT("ES_GameMode: Divine Tick loop initialized with interval %f"), DivineTickInterval);
}

void AES_GameMode::ExecuteDivineTick()
{
    // Find the Divine Overseer component in the world to process the tick
    // In a production setup, we might fetch this from the GameState
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), FoundActors);

    bool bTickProcessed = false;

    for (AActor* Actor : FoundActors)
    {
        if (Actor)
        {
            // Attempt to find the Divine Overseer Component on actors
            UActorComponent* Component = Actor->GetComponentByClass(UActorComponent::StaticClass()); 
            // Note: In actual implementation, we would use UES_DivineOverseerComponent::StaticClass()
            
            // For this architectural step, we simulate the call to the component
            UE_LOG(LogTemp, Log, TEXT("ES_GameMode: Triggering Divine Tick on Actor: %s"), *Actor->GetName());
            bTickProcessed = true;
            break; // Only trigger once per game-wide tick
        }
    }

    if (!bTickProcessed)
    {
        UE_LOG(LogTemp, Warning, TEXT("ES_GameMode: Divine Tick attempted but no Overseer found!"));
    }
}
