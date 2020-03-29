#include "rgbimage.h"
#include "color.h"
#include "assert.h"

RGBImage::RGBImage(unsigned int Width, unsigned int Height) :m_Width(Width), m_Height(Height)
{
	m_Image = new Color[Width * Height];
}

RGBImage::~RGBImage()
{
	free(m_Image);
}

void RGBImage::setPixelColor(unsigned int x, unsigned int y, const Color& c)
{
	if (x < 0 || x >= m_Width || y < 0 || y >= m_Height) {
		throw "Coordinates outside of Image!";
	}
	//printf("Setting pixel (%d,%d) to RGB(%f,%f,%f)\n", x, y, c.R, c.G, c.B);
	m_Image[x + y * m_Width] = c;
}

const Color& RGBImage::getPixelColor(unsigned int x, unsigned int y) const
{
	if (x < 0 || x >= m_Width || y < 0 || y >= m_Height) {
		throw "Coordinates outside of Image!";
	}
	return m_Image[x + y * m_Width];
}

unsigned int RGBImage::width() const
{
	return m_Width;
}
unsigned int RGBImage::height() const
{
	return m_Height;
}

unsigned char RGBImage::convertColorChannel(float v)
{
	if (v < 0) {
		v = 0.0f;
	}
	else if (v > 1) {
		v = 1.0f;
	}
	//printf("%f -> %d\n", v, (unsigned char)(v * 255.0f));
	return (char)(v * 255.0f); // dummy (remove)
}


bool RGBImage::saveToDisk(const char* Filename)
{
	bfSize_t bfSize = bfOffBits + (m_Width * m_Height * biBitCount);
	biWidth_t biWidth = m_Width;
	biHeight_t biHeight = m_Height;
	biSizeImage_t biSizeImage = m_Width * m_Height * biBitCount;

	FILE* file = fopen(Filename, "w");
	fwrite(&bfType, sizeof(bfType_t), 1, file);
	fwrite(&bfSize, sizeof(bfSize_t), 1, file);
	fwrite(&bfReserved, sizeof(bfReserved_t), 1, file);
	fwrite(&bfOffBits, sizeof(bfOffBits_t), 1, file);
	fwrite(&biSize, sizeof(biSize_t), 1, file);
	fwrite(&biWidth, sizeof(biWidth_t), 1, file);
	fwrite(&biHeight, sizeof(biHeight_t), 1, file);
	fwrite(&biPlanes, sizeof(biPlanes_t), 1, file);
	fwrite(&biBitCount, sizeof(biBitCount_t), 1, file);
	fwrite(&biCompression, sizeof(biCompression_t), 1, file);
	fwrite(&biSizeImage, sizeof(biSizeImage_t), 1, file);
	fwrite(&biXPelsPerMeter, sizeof(biXPelsPerMeter_t), 1, file);
	fwrite(&biYPelsPerMeter, sizeof(biYPelsPerMeter_t), 1, file);
	fwrite(&biClrUsed, sizeof(biClrUsed_t), 1, file);
	fwrite(&biClrImportant, sizeof(biClrImportant_t), 1, file);
	/*
	char* imgData = new char[m_Width * m_Height * 3];
	for (int i = 0; i < m_Width * m_Height; i++) {
		Color current = m_Image[i];
		imgData[3 * i] = 255; convertColorChannel((i % m_Width) / (float)m_Width);
		imgData[3 * i + 1] = 0;// i % 255; // convertColorChannel(current.G);
		imgData[3 * i + 2] = 0;// i % 255; // convertColorChannel(current.B);
		//printf("Current RGB(%f,%f,%f) i:%d", current.R, current.G, current.B, i);
	}
	fwrite(imgData, sizeof(char), m_Width * m_Height * 3, file);
	*/
	char padding = 0x00;
	fwrite(&padding, sizeof(char), 1, file);
	for (int y = m_Height - 1; y >= 0; y--) {
		for (int x = 0; x < m_Width; x++) {
			Color current = getPixelColor(x, y);
			unsigned char red = 0xff;// convertColorChannel(current.R);
			unsigned char green = 0xaa;// convertColorChannel(current.G);
			unsigned char blue = 0x00;// convertColorChannel(current.B);
			fwrite(&red, sizeof(char), 1, file);
			fwrite(&green, sizeof(char), 1, file);
			fwrite(&blue, sizeof(char), 1, file);
		}
	}
	fclose(file);
	return false; // dummy (remove)
}
