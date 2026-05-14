#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CodexDataAsset.h"
#include "CodexNotificationWidget.generated.h"

UCLASS()
class ETERNALSUMMIT_API UCodexNotificationWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Function to populate the widget with new entry data
	UFUNCTION(BlueprintCallable, Category = "Codex UI")
	void DisplayNewEntry(const FCodexEntry& NewEntry);

protected:
	// UI Bindings (to be set in Blueprint)
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TitleText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DescriptionText;

	// Function to hide the widget after a delay
	UFUNCTION(BlueprintCallable, Category = "Codex UI")
	void HideWidget();
};