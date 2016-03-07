#include "glwidget.h"
#include <iostream>

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeGL()
{
//    if(!gladLoadGL())
//    {
//        std::cout << "Failed to initialize OpenGL context" << std::endl;
//        exit(10);
//    }
}

void GLWidget::resizeGL(int w, int h)
{
    std::cout << w << " " << h <<std::endl;
}

void GLWidget::paintGL()
{

}
