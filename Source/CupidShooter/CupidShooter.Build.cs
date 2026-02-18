// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CupidShooter : ModuleRules
{
	public CupidShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"CupidShooter",
			"CupidShooter/Variant_Horror",
			"CupidShooter/Variant_Horror/UI",
			"CupidShooter/Variant_Shooter",
			"CupidShooter/Variant_Shooter/AI",
			"CupidShooter/Variant_Shooter/UI",
			"CupidShooter/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
