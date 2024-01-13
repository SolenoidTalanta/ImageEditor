#pragma once
#include <iostream>
#include <fstream>
#include <vector>

struct ImageData 
{
	int width;
	int height;
	std::vector<uint8_t> data;
};

class ImageFileReader
{
public:
	enum class Type
	{
		BMP
	};

private:
	Type m_type;
	const char* filePath;

	ImageData LoadImageDataBmp();

public:

	ImageFileReader(const char* filePath, Type type);

	ImageData LoadImageData();
};

