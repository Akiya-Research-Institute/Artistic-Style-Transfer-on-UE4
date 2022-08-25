# Artistic Style Transfer on UE5

Example UE4 project for artistic style transfer, where a new image is created based on two inputs, one representing the artistic style and one representing the content.  
[(日本語の説明はこちら)](https://akiya-research-institute.github.io/NNEngine-API/ja/demo-project-overview-style-transfer/
)

https://user-images.githubusercontent.com/36610547/154606606-eec1763d-8247-4ead-ad3c-ef085ca258d5.mp4

## Environment

- OS: Windows 10 64bit
- Unreal Engine: 5.0.3
- [NNEngine plugin](https://www.unrealengine.com/marketplace/product/74892c770dc149b1b5c4e872804e6ade) v1.2 or above

## Download

Please download from the [release](https://github.com/Akiya-Research-Institute/Artistic-Style-Transfer-on-UE4/releases) page.

## Run the demo

1. Extract the downloaded zip file and double-click `ArtStyleTransfer.uproject`.  
2. After launching, follow the tutorial of `/Content/NNEngineDemo-ArtisticStyleTransfer/Tutorial_ArtisticStyleTransfer.uasset`.

## Add an artistic Style

You can add a style by dragging and dropping any image file into the UE4 content browser to create a Texture asset, and then specifying it as the `Style Texture` of the `ArtisticStyleTransferer` actor.

## Model details

See the following pages for the details of the model used in this project.

- [Exploring the structure of a real-time, arbitrary neural artistic stylization network](https://arxiv.org/abs/1705.06830)
- [TFLite Tutorial](https://www.tensorflow.org/lite/examples/style_transfer/overview)
