// Copyright 2022 Akiya Research Institute, Inc. All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class ArtStyleTransferTarget : TargetRules
{
	public ArtStyleTransferTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ArtStyleTransfer" } );
	}
}
