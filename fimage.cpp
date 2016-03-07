#include "fimage.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <memory>
#include <cassert>

//#include "utils.h"

fImage::fImage()
    : Image()
{

}

fImage::~fImage()
{
    _image.clear();
}

void writeImageToPathT(const fipImage& image, const std::string& path)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto saved = image.save(path.c_str());
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_mseconds = static_cast<std::chrono::duration<double, std::milli>> (end - start);
    std::cout << "IMAGE time writing the image: " << elapsed_mseconds.count() << std::endl;
    if (!saved)
    {
        std::cerr << "FAILED TO SAVE" << std::endl;
    }
}

void fImage::writeImage(const std::string& path)
{
#ifdef THREADED_IMAGE_WRITE
    //std::thread t1;
    //if(t1.joinable()) t1.join();
    std::thread saver(writeImageToPathT, _image, path);
    saver.detach();
#else
    writeImageToPath(path);
#endif
}

void fImage::writeImageToPath(const std::string& path)
{
    auto b = _image.save(path.c_str());
    if (!b)
    {
        std::cerr << "FAILED TO SAVE" << std::endl;
        //throw_non_critical("FAILED TO SAVE");
    }
}

unsigned int fImage::getHeight()
{
    return _image.getHeight();
}

unsigned int fImage::getWidth()
{
    return _image.getWidth();
}

unsigned char* fImage::getImageData()
{
    return static_cast<unsigned char*>(_image.accessPixels());
}

void  fImage::loadImage(const void* buffer, unsigned int width, unsigned int height, unsigned int bpp)
{
    ////fipImage (FREE_IMAGE_TYPE image_type=FIT_BITMAP, unsigned width=0, unsigned height=0, unsigned bpp=0)
    _image = fipImage(FIT_BITMAP, width, height, bpp);
    std::memcpy(_image.accessPixels(), buffer, width * height * (bpp / 8));
}

void  fImage::loadImage(const std::string& path)
{
    loadFromPath(path);
    //bool load = _image.convertTo24Bits();
    //bool load = _image.convertToType(FIT_BITMAP);

}

void fImage::loadFromPath(const std::string& path)
{
    if (!_image.load(path.c_str()))
    {
        std::cerr << "Can not load the image " + path << std::endl;
        //throw_non_critical("Can not load the image " + path);
        assert(false);
    }
    else
    {
        //_image.flipVertical();
    }
}

GLint fImage::getOpenGLFormat()
{
    return GL_RGB;
}

GLint fImage::getOpenGLImageType()
{
    return GL_UNSIGNED_BYTE;

}

GLint fImage::getOpenGLImageInternalFormat()
{
    return GL_RGB8;
}

void fImage::flipDiagonal()
{
    assert(_image.flipHorizontal() && _image.flipVertical());
}
