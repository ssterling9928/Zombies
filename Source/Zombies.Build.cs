// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Zombies : ModuleRules
{
	public Zombies(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule", "VisualStudioTools" });
	}
}
