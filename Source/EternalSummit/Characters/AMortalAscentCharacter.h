#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "AMortalAscentCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class ETERNALSUMMIT_API AMortalAscentCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMortalAscentCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void ApplyEnvironmentalEffects();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (Allowlist = "Default"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* JumpAction;

private:
	FVector InputVector;
};
