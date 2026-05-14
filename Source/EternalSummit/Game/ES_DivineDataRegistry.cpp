#include "ES_DivineDataRegistry.h"
#include "Misc/FileHelper.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"

void UES_DivineDataRegistry::LoadDivineData(FString FilePath)
{
    FString JsonString;
    if (!FFileHelper::LoadFileToString(JsonString, *FilePath))
    {
        UE_LOG(LogTemp, Error, TEXT("ES_DivineDataRegistry: Failed to load file at %s"), *FilePath);
        return;
    }

    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
    TSharedPtr<FJsonObject> JsonObject;

    if (FJsonSerializer::Deserialize(Reader, JsonObject))
    {
        LoadedEvents.Empty();
        const TArray<TSharedPtr<FJsonValue>>* DivineEventsArray;
        
        if (JsonObject->TryGetArrayField(TEXT("DivineEvents"), DivineEventsArray))
        {
            for (const TSharedPtr<FJsonValue>& Value : *DivineEventsArray)
            {
                TSharedPtr<FJsonObject> EventObject = Value->AsObject();
                FDivineEventData NewEvent;

                // Manually mapping or using JsonObjectConverter
                // For stability in this build, we use the converter on the object
                if (FJsonObjectConverter::JsonObjectToUStruct(EventObject.ToSharedRef(), &NewEvent))
                {
                    LoadedEvents.Add(NewEvent);
                }
            }
            UE_LOG(LogTemp, Log, TEXT("ES_DivineDataRegistry: Successfully loaded %d divine events."), LoadedEvents.Num());
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("ES_DivineDataRegistry: Failed to parse JSON."));
    }
}
