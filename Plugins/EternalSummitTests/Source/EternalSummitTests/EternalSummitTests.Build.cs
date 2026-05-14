using UnrealBuildTool;

public class EternalSummitTests : ModuleRules
{
    public EternalSummitTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "EternalSummit"
        });
    }
}
