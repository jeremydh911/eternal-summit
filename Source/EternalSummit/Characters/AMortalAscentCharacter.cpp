#include "AMortalAscentCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/LogMacros.h"

AMortalAscentCharacter::AMortalAscentCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    InputVector = FVector::ZeroVector;
}

void AMortalAscentCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            if (DefaultMappingContext)
            {
                Subsystem->AddMappingContext(DefaultMappingContext, 0);
            }
        }
    }
}

void AMortalAscentCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ApplyEnvironmentalEffects();
}

void AMortalAscentCharacter::ApplyEnvironmentalEffects()
{
    // Environmental influence logic has not been wired up yet.
}