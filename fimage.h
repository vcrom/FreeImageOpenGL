#ifndef FIMAGE_H
#define FIMAGE_H

#include "Image.h"
#include <FreeImage\FreeImagePlus.h>
#include <glad/glad.h>

#define THREADED_IMAGE_WRITE

class fImage : public Image
{
public:
    fImage();
    ~fImage();

    void loadImage(const void* buffer, unsigned int width, unsigned int height, unsigned int bpp = 32); //default RGBA 8-bits per channel
    void loadImage(const std::string& path);
    bool isLoaded();
    void writeImage(const std::string& path);
    unsigned int getHeight();
    unsigned int getWidth();
    unsigned char* getImageData();
    GLint getOpenGLFormat();
    GLint getOpenGLImageType();
    GLint getOpenGLImageInternalFormat();
    void flipDiagonal();
    std::size_t getBitsPerChannel();
    std::size_t getBitsPerPixel();


private:
    void printImageInfo();

    fipImage _image;
    bool _loaded;
};

#endif // FIMAGE_H
