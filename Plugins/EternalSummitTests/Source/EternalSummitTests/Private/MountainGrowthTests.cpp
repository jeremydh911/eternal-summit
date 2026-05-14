#include "Misc/AutomationTest.h"
#include "ES_MountainProceduralManager.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FMountainGrowthStateTransitionTest,
    "EternalSummit.Mountain.StateTransitions",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FMountainGrowthStateTransitionTest::RunTest(const FString& Parameters)
{
    UES_MountainProceduralManager* BlessedManager = NewObject<UES_MountainProceduralManager>();
    TestNotNull(TEXT("Blessed manager should be created"), BlessedManager);
    if (!BlessedManager)
    {
        return false;
    }

    TestEqual(TEXT("Initial state should be Seed"), BlessedManager->GetCurrentState(), EMountainGrowthState::Seed);

    BlessedManager->HandleDivineBlessing(0.9f);
    TestEqual(TEXT("High blessing should transition to Blessed"), BlessedManager->GetCurrentState(), EMountainGrowthState::Blessed);

    UES_MountainProceduralManager* CorruptedManager = NewObject<UES_MountainProceduralManager>();
    TestNotNull(TEXT("Corrupted manager should be created"), CorruptedManager);
    if (!CorruptedManager)
    {
        return false;
    }

    CorruptedManager->HandleDivineSmite(1.0f);
    TestEqual(TEXT("High smite should transition to Corrupted"), CorruptedManager->GetCurrentState(), EMountainGrowthState::Corrupted);

    return true;
}
