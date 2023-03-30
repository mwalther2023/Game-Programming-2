// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameProg2 : ModuleRules
{
	public GameProg2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
