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
    _loaded = false;
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
    std::thread saver(writeImageToPathT, _image, path);
    saver.detach();
#else
    writeImageToPathT(_image, path);
#endif
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

void fImage::printImageInfo()
{
    std::cout << "Type: ";
    switch(_image.getImageType())
    {
        case FIT_BITMAP:
            std::cout << "BITMAP";
        break;
        case FIT_UINT16:
            std::cout << "Unsigned short";
        break;
        case FIT_INT16:
        case FIT_RGB16:
        case FIT_RGBA16:
            std::cout << "Short";
        break;
        case FIT_UINT32:
            std::cout << "Unsigned int";
        break;
        case FIT_INT32:
            std::cout << "Int";
        break;
        case FIT_FLOAT:
        case FIT_RGBF:
        case FIT_RGBAF:
            std::cout << "Float";
        break;
        case FIT_DOUBLE:
            std::cout << "Double";
        break;
        case FIT_COMPLEX:
            std::cout << "Complex";
        break;
        case FIT_UNKNOWN:
            std::cout << "Unknown";
        break;
    }
    std::cout << std::endl;

    std::cout << "Color Type: ";
    switch(_image.getColorType())
    {
        case FIC_MINISBLACK:
        std::cout << "MINSBLA";
        break;
        case FIC_MINISWHITE:
        std::cout << "MINSWHI";
        break;
        case FIC_PALETTE:
        std::cout << "PALLETE";
        break;
        case FIC_RGB:
        std::cout << "RGB";
        break;
        case FIC_RGBALPHA:
        std::cout << "RGBA";
        break;
    }
    std::cout << std::endl;

    auto size = getBitsPerChannel();
    auto bpp = getBitsPerPixel();
    std::cout << "Bpp: " << bpp << std::endl;
    std::cout << "Channel size: " << size << std::endl;
    std::cout << "Channels: " << bpp/size << std::endl;

}

void  fImage::loadImage(const std::string& path)
{
    if (!_image.load(path.c_str()))
    {
        std::cerr << "Can not load the image " + path << std::endl;
    }
    else
    {
        _loaded = true;
    #ifdef _DEBUG
        std::cout << "Image " + path + " loaded" << std::endl;
        printImageInfo();
    #endif
        //Convert the image if its format is not supported by openGL
        switch(_image.getImageType())
        {
            case FIT_DOUBLE:
            case FIT_COMPLEX:
                _image.convertToFloat();
        }
    }
}

bool fImage::isLoaded()
{
    return _loaded;
}

GLint fImage::getOpenGLFormat()
{
    auto size = getBitsPerChannel();
    auto bpp = getBitsPerPixel();
    auto channels = bpp/size;
    switch(channels)
    {
        case 0:
        case 1:
            switch(_image.getImageType())
            {
                case FIT_UINT32:
                case FIT_INT32:
                    return GL_RED_INTEGER;
                default:
                return GL_RED;
            }
        case 2:
            switch(_image.getImageType())
            {
                case FIT_UINT32:
                case FIT_INT32:
                    return GL_RG_INTEGER;
                default:
                return GL_RG;
            }
        case 3:
            switch(_image.getImageType())
            {
                case FIT_UINT32:
                case FIT_INT32:
                #if (defined(FREEIMAGE_COLORORDER) && FREEIMAGE_COLORORDER == FREEIMAGE_COLORORDER_BGR)
                    return GL_BGR_INTEGER;
                #else
                    return GL_RGB_INTEGER
                #endif
                    break;
                case FIT_BITMAP:
                #if (defined(FREEIMAGE_COLORORDER) && FREEIMAGE_COLORORDER == FREEIMAGE_COLORORDER_BGR)
                    return GL_BGR;
                #else
                    return GL_RGB;
                #endif
                    break;
                default:
                    return GL_RGB;
            }
        case 4:
            switch(_image.getImageType())
            {
                case FIT_UINT32:
                case FIT_INT32:
                #if (defined(FREEIMAGE_COLORORDER) && FREEIMAGE_COLORORDER == FREEIMAGE_COLORORDER_BGR)
                    return GL_BGRA_INTEGER;
                #else
                    return GL_RGBA_INTEGER
                #endif
                    break;
                case FIT_BITMAP:
                #if (defined(FREEIMAGE_COLORORDER) && FREEIMAGE_COLORORDER == FREEIMAGE_COLORORDER_BGR)
                    return GL_BGRA;
                #else
                    return GL_RGBA;
                #endif
                    break;
                default:
                    return GL_RGBA;
            }
    }
    assert(false);
    return 0;

}

GLint fImage::getOpenGLImageType()
{
    switch(_image.getImageType())
    {
        case FIT_BITMAP:
            return GL_UNSIGNED_BYTE;
        break;
        case FIT_UINT16:
            return GL_UNSIGNED_SHORT;
        break;
        case FIT_INT16:
        case FIT_RGB16:
        case FIT_RGBA16:
            return GL_SHORT;
        break;
        case FIT_UINT32:
            return GL_UNSIGNED_INT;
        break;
        case FIT_INT32:
            return GL_INT;
        break;
        case FIT_FLOAT:
        case FIT_RGBF:
        case FIT_RGBAF:
            return GL_FLOAT;
        break;
//        case FIT_DOUBLE:
//            return no openGL format;
//        break;
//        case FIT_COMPLEX:
//            return no openGL format;
//        break;
    }
    assert(false); //Format FIT_UNKNOWN
    return 0;
}

GLint fImage::getOpenGLImageInternalFormat()
{
    return GL_RGB;
}

void fImage::flipDiagonal()
{
    assert(_image.flipHorizontal() && _image.flipVertical());
}


std::size_t fImage::getBitsPerChannel()
{
    auto size = static_cast<std::size_t>(0);
    //set component size
    switch(_image.getImageType())
    {
        case FIT_BITMAP:
            size = sizeof(unsigned char);
        break;
        case FIT_UINT16:
            size = sizeof(unsigned short);
        break;
        case FIT_INT16:
        case FIT_RGB16:
        case FIT_RGBA16:
            size = sizeof(short);
        break;
        case FIT_UINT32:
            size = sizeof(unsigned int);
        break;
        case FIT_INT32:
            size = sizeof(int);
        break;
        case FIT_FLOAT:
        case FIT_RGBF:
        case FIT_RGBAF:
            size = sizeof(float);
        break;
        default:
            //Format Not supported by OpenGL
            assert(false);
    }
    size *= CHAR_BIT;
    return size;
}

std::size_t fImage::getBitsPerPixel()
{
    return _image.getBitsPerPixel();
}
