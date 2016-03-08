#include "glwidget.h"

#include <iostream>
#include <QFileDialog>
#include <QMessageBox>

#include "screenquad.h"
#include "utils.h"
#include "fimage.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

GLWidget::~GLWidget()
{

}

void GLWidget::loadImage()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "./images/", tr("All files (*)"));
    if(filename.length() > 0) loadImageFromPath(filename);
}

void GLWidget::loadImageFromPath(const QString &path)
{
    fImage image;
    image.loadImage(path.toStdString());
    if(image.isLoaded())
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, _texture_id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getWidth(), image.getHeight(), 0, image.getOpenGLFormat(), image.getOpenGLImageType(), image.getImageData());
        checkOpenGLError();
        update();
        auto aux = path.split("/");
        emit imageLoaded(aux.at(aux.length()-1));
    }
    else QMessageBox::information(this, tr("Error"), "Image " + path + "\n Can not be loaded.");
}

void GLWidget::initializeGL()
{
    //Init glad
    if(!gladLoadGL())
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        exit(10);
    }
    std::cout << "OpenGL " << glGetString(GL_VERSION) << ", GLSL " <<  glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    //Init shader
    _shader = std::shared_ptr<GlslShader>(new GlslShader());
    _shader->loadFromFile(GL_VERTEX_SHADER, "shaders/screen_space_quad.vert");
    _shader->loadFromFile(GL_FRAGMENT_SHADER, "shaders/screen_space_quad.frag");
//#ifdef Q_OS_WIN32
//    _shader->loadFromFile(GL_VERTEX_SHADER, "shaders\\screen_space_quad.vert");
//    _shader->loadFromFile(GL_FRAGMENT_SHADER, "shaders\\screen_space_quad.frag");
//#elif Q_OS_LINUX
//    _shader->loadFromFile(GL_VERTEX_SHADER, "shaders/screen_space_quad.vert");
//    _shader->loadFromFile(GL_FRAGMENT_SHADER, "shaders/screen_space_quad.frag");
//#endif
    _shader->createAndLinkProgram();
    _shader->use();
    _shader->addAttribute("vVertex");
    _shader->addUniform("color_texture");
    _shader->setUniform("color_texture", 0);
    _shader->unUse();
    checkOpenGLError();

    //Init texture
    glGenTextures(1, &_texture_id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    checkOpenGLError();

    //load example image
    loadImageFromPath("images/img1.jpg");
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture_id);
    _shader->use();
    ScreenQuad::getInstance()->render();
    _shader->unUse();
}
