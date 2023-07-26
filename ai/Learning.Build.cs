// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Learning : ModuleRules
{
	public Learning(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
        PublicDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
        PublicDependencyModuleNames.AddRange(new string[] { "AIModule", "GameplayTasks" });
    }
}
