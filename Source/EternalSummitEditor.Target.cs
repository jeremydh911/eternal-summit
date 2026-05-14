using UnrealBuildTool;
using System.Collections.Generic;

public class EternalSummitEditorTarget : TargetRules
{
	public EternalSummitEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("EternalSummit");
	}
}