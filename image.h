#ifndef IMAGE_H
#define IMAGE_H

#include <string>

//static_assert (CHAR_BIT * sizeof (float) == 32, "Size of float is not 32bits");

class Image
{
public:
    Image()= default;
    virtual ~Image() = default;

    virtual void loadImage(const void* buffer, unsigned int width, unsigned int height, unsigned int bpp) = 0;
    virtual void loadImage(const std::string& path) = 0;
    virtual bool isLoaded() = 0;
    virtual void writeImage(const std::string& path) = 0;
    virtual unsigned int getHeight() = 0;
    virtual unsigned int getWidth() = 0;
    virtual unsigned char* getImageData() = 0;
};

#endif // IMAGE_H
