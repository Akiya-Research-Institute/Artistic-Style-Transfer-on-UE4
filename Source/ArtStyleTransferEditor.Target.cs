// Copyright 2022 Akiya Research Institute, Inc. All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class ArtStyleTransferEditorTarget : TargetRules
{
	public ArtStyleTransferEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ArtStyleTransfer" } );
	}
}
