#include "glwidget.h"

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

}

void GLWidget::resizeGL(int w, int h)
{

}

void GLWidget::paintGL()
{

}
