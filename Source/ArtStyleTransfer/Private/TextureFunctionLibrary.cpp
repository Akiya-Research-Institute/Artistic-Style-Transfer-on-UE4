// Copyright 2022 Akiya Research Institute, Inc. All Rights Reserved


#include "TextureFunctionLibrary.h"
#include "Async/ParallelFor.h"

UTexture2D* UTextureFunctionLibrary::CreateTexture2d_BGRA_Byte(const int32 width, const int32 height)
{
	return UTexture2D::CreateTransient(width, height, PF_B8G8R8A8);
}

void UTextureFunctionLibrary::CopyByteArrayToTexture2D_BGR_To_BGRA(const TArray<uint8>& in_data, UPARAM(ref)UTexture2D* out_texture2D, const bool useMultiThread, const bool CHW_to_HWC)
{
	const int numOfPixels = out_texture2D->GetSizeX() * out_texture2D->GetSizeY();
	const int numOfPixels2 = numOfPixels + numOfPixels;

	FTexture2DMipMap& Mip = out_texture2D->PlatformData->Mips[0];
	void* TextureData = Mip.BulkData.Lock(LOCK_READ_WRITE);
	uint8* TextureDataByte = (uint8*)TextureData;

	if (CHW_to_HWC)
	{
		if (useMultiThread)
		{
			ParallelFor(numOfPixels, [TextureDataByte, &in_data, numOfPixels, numOfPixels2](int32 i)
				{
					const int outOffset = i * 4;
					TextureDataByte[outOffset + 0] = in_data[i               ]; // R
					TextureDataByte[outOffset + 1] = in_data[i + numOfPixels ]; // G
					TextureDataByte[outOffset + 2] = in_data[i + numOfPixels2]; // B
				  //TextureDataByte[outOffset + 3] = 0;                         // A = 0
				});
		}
		else
		{
			for (int i = 0; i < numOfPixels; i++)
			{
				const int outOffset = i * 4;
				TextureDataByte[outOffset + 0] = in_data[i               ]; // R
				TextureDataByte[outOffset + 1] = in_data[i + numOfPixels ]; // G
				TextureDataByte[outOffset + 2] = in_data[i + numOfPixels2]; // B
			  //TextureDataByte[outOffset + 3] = 0;                         // A = 0
			}
		}
	}
	else
	{
		if (useMultiThread)
		{
			ParallelFor(numOfPixels, [TextureDataByte, &in_data, numOfPixels, numOfPixels2](int32 i)
				{
					const int inOffset = i * 3;
					const int outOffset = i * 4;
					TextureDataByte[outOffset + 0] = in_data[inOffset    ]; // R
					TextureDataByte[outOffset + 1] = in_data[inOffset + 1]; // G
					TextureDataByte[outOffset + 2] = in_data[inOffset + 2]; // B
				  //TextureDataByte[outOffset + 3] = 0;                     // A = 0
				});
		}
		else
		{
			for (int i = 0; i < numOfPixels; i++)
			{
				const int inOffset = i * 3;
				const int outOffset = i * 4;
				TextureDataByte[outOffset + 0] = in_data[inOffset    ]; // R
				TextureDataByte[outOffset + 1] = in_data[inOffset + 1]; // G
				TextureDataByte[outOffset + 2] = in_data[inOffset + 2]; // B
			  //TextureDataByte[outOffset + 3] = 0;                     // A = 0
			}
		}
	}

	Mip.BulkData.Unlock();
	out_texture2D->UpdateResource();
}
