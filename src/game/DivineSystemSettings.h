USTRUCT(BlueprintType)
struct FDivineSystemSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine System")
    float EvilThresholdBase = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine System")
    float EvilDecayPerDay = 15.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine System")
    float DisasterProbability = 0.12f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Divine System")
    float BlessingProbability = 0.08f;
};
