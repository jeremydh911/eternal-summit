UCLASS(BlueprintType)
class ADivineEventManager : public AActor
{
    GENERATED_BODY()

public:
    ADivineEventManager();

    // Reference to the Data Asset for Live-Ops tuning
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine")
    UDivineSystemDataAsset* DivineDataAsset;

    // Visual feedback via Blueprints (e.g., Bible page aesthetics)
    UFUNCTION(BlueprintImplementableEvent, Category = "Divine")
    void OnDivineEventTriggered(bool bIsDisaster, float Intensity);

protected:
    // Handles client-side prediction and visual cues
    UFUNCTION(BlueprintCallable, Category = "Divine")
    void PredictDivineEvent();

    // Reconciliation triggered by server authority
    UFUNCTION(BlueprintCallable, Category = "Divine")
    void ReconcileDivineEvent(bool bServerDisaster, float ServerIntensity);
};
