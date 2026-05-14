#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CodexDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FCodexEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EntryID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Illustration = nullptr;
};

UCLASS(BlueprintType)
class ETERNALSUMMIT_API UCodexDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Codex")
	TArray<FCodexEntry> Entries;
};