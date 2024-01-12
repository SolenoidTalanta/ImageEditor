#include "ImageFileReader.h"

int main() {
    const char filePath[] = "./../../DebugAssets/ImageSamples/BlackWhite2x2.bmp";
    ImageFileReader ir(filePath, ImageFileReader::Type::BMP);
    ImageData imageData = ir.LoadImageData();

    // Wyœwietl informacje o obrazie
    std::cout << "Wymiary: " << imageData.width << "x" << imageData.height << " pikseli" << std::endl;


    return 0;
}