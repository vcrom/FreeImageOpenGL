#ifndef UTILS_H
#define UTILS_H

#ifndef GL_CHECK_ERRORS
    #define GL_CHECK_ERRORS assert(glGetError()== GL_NO_ERROR);
#endif

#ifndef GL_CHECK_ERRORS_PRINT
    #define GL_CHECK_ERRORS_PRINT {GLenum err; while ((err = glGetError()) != GL_NO_ERROR) {std::cerr << "OpenGL error: " << err << std::endl;}}
#endif


#ifdef _DEBUG
    #define checkOpenGLError() GL_CHECK_ERRORS
    #define printOpenGLError() GL_CHECK_ERRORS_PRINT
#else
    #define checkOpenGLError()
    #define printOpenGLError()
#endif

#endif // UTILS_H
