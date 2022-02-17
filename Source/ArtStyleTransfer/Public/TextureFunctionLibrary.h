// Copyright 2022 Akiya Research Institute, Inc. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TextureFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ARTSTYLETRANSFER_API UTextureFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Texture processing")
		/**
		* Create Texture2D with 4(BGRA) color channel of byte
		* @param width Texture width
		* @param height Texture height
		*/
		static UTexture2D* CreateTexture2d_BGRA_Byte(const int32 width, const int32 height);

	UFUNCTION(BlueprintCallable, Category = "Texture processing")
		/**
		* Fill Texture2D data by byte array while converting CHW-RGB format to HWC-BGRA format.
		* @param source_data Input data copied to texture. (Channel x Height x Width), RGB format.
		* @param destination_texture2D Texture to be filled. (Width x Height x Channel), BGRA format.
		* @param useMultiThread Whether to use multithread to copy the data
		* @param CHW_to_HWC Whether to convert the image from (Channel x Height x Width) to (Width x Height x Channel) format. If false, the input data is assumed to be in (Width x Height x Channel) format.
		*/
		static void CopyByteArrayToTexture2D_BGR_To_BGRA(const TArray<uint8>& source_data, UPARAM(ref) UTexture2D* destination_texture2D, const bool useMultiThread = true, const bool CHW_to_HWC = true);
};
