#include "Misc/AutomationTest.h"
#include "ES_OverseerSystem.h"
#include "ES_MountainProceduralManager.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FOverseerSystemDispatchTest,
    "EternalSummit.Overseer.ActionDispatch",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FOverseerSystemDispatchTest::RunTest(const FString& Parameters)
{
    UES_OverseerSystem* Overseer = NewObject<UES_OverseerSystem>();
    TestNotNull(TEXT("Overseer should be created"), Overseer);
    if (!Overseer)
    {
        return false;
    }

    UES_MountainProceduralManager* SmiteManager = NewObject<UES_MountainProceduralManager>();
    TestNotNull(TEXT("Smite manager should be created"), SmiteManager);
    if (!SmiteManager)
    {
        return false;
    }

    Overseer->MountainManager = SmiteManager;
    Overseer->RequestMountainAction(EOverseerAction::Smite, 1.0f);
    TestEqual(TEXT("Smite should dispatch to the mountain manager"), SmiteManager->GetCurrentState(), EMountainGrowthState::Corrupted);

    UES_MountainProceduralManager* BlessManager = NewObject<UES_MountainProceduralManager>();
    TestNotNull(TEXT("Bless manager should be created"), BlessManager);
    if (!BlessManager)
    {
        return false;
    }

    Overseer->MountainManager = BlessManager;
    Overseer->RequestMountainAction(EOverseerAction::Bless, 0.9f);
    TestEqual(TEXT("Bless should dispatch to the mountain manager"), BlessManager->GetCurrentState(), EMountainGrowthState::Blessed);

    UES_MountainProceduralManager* NurtureManager = NewObject<UES_MountainProceduralManager>();
    TestNotNull(TEXT("Nurture manager should be created"), NurtureManager);
    if (!NurtureManager)
    {
        return false;
    }

    Overseer->MountainManager = NurtureManager;
    Overseer->RequestMountainAction(EOverseerAction::Nurture, 0.9f);
    TestEqual(TEXT("Nurture should currently route through blessing"), NurtureManager->GetCurrentState(), EMountainGrowthState::Blessed);

    return true;
}
