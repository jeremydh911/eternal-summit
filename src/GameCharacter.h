#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameCharacter.generated.h"

UCLASS()
class KINGOFTHESHILL_API AGameCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AGameCharacter();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AttackPower;

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void TakeDamage(float DamageAmount);
};

#endif // GAMECHARACTER_H