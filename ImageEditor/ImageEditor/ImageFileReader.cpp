#include "ImageFileReader.h"

ImageFileReader::ImageFileReader(const char* filePath, Type type)
    : filePath(filePath), m_type(type)
{

}

ImageData ImageFileReader::LoadImageDataBmp()
{
    ImageData imageData;

    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "B³ad: Nie mozna otworzyc pliku." << std::endl;
        std::cerr << "Sciezka: " << filePath << std::endl;
        return imageData;
    }

    // Poczytaj nag³ówek BMP (jeœli zak³adasz, ¿e plik to BMP)
    char header[54];
    file.read(header, sizeof(header));

    // Ustaw wymiary obrazu
    imageData.width = *reinterpret_cast<int*>(&header[18]);
    imageData.height = *reinterpret_cast<int*>(&header[22]);

    // Przesuñ wskaŸnik pliku na pocz¹tek danych obrazu
    file.seekg(*reinterpret_cast<int*>(&header[10]), std::ios::beg);

    // Wczytaj dane obrazu do tablicy danych
    imageData.data.resize(imageData.width * imageData.height * 3); // 3 kana³y (RGB) dla uproszczenia
    file.read(reinterpret_cast<char*>(imageData.data.data()), imageData.data.size());

    file.close();

    return imageData;
}

ImageData ImageFileReader::LoadImageData()
{
    switch (this->m_type)
    {
    case Type::BMP: 
        return LoadImageDataBmp();
    default:
        std::cerr << "Error: Unexpected image file extension! \n";
        break;
    }
}

