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

    void loadImage(const void* buffer, unsigned int width, unsigned int height, unsigned int bpp = 24);
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

private:
    fipImage _image;
    bool _loaded;
};

#endif // FIMAGE_H
