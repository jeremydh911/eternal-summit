UCLASS(BlueprintType)
class UDivineSystemDataAsset : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine System")
    FDivineSystemSettings Settings;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine System")
    float DisasterSeverityMultiplier = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine System")
    float CodexBuffScalingFactor = 0.05f;
};
