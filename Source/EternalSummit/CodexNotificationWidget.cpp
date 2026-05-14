#include "CodexNotificationWidget.h"
#include "Components/TextBlock.h"
#include "TimerManager.h"

void UCodexNotificationWidget::DisplayNewEntry(const FCodexEntry& NewEntry)
{
	if (TitleText)
	{
		TitleText->SetText(FText::FromString(NewEntry.Title.ToString()));
	}

	if (DescriptionText)
	{
		DescriptionText->SetText(FText::FromString(NewEntry.Description.ToString()));
	}

	// Make the widget visible
	SetVisibility(ESlateVisibility::Visible);

	// Automatically hide the widget after 5 seconds
	FTimerHandle HideTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(
		HideTimerHandle,
		this, 
		&UCodexNotificationWidget::HideWidget, 
		5.0f, 
		false
	);
}

void UCodexNotificationWidget::HideWidget()
{
	SetVisibility(ESlateVisibility::Hidden);
}