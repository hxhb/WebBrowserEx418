// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WebBrowserEx : ModuleRules
{
    public WebBrowserEx(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "WebBrowser",
                    "Slate",
                    "SlateCore",
                    "UMG",
                    "WebBrowserWidget",
                    "ApplicationCore"
			}
        );
    }
}
