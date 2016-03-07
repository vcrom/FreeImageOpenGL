#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <glad/glad.h>
#include <QObject>
#include <QOpenGLWidget>
#include <memory>

#include "glslshader.h"

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
signals:
    void imageLoaded(const QString &path);

public slots:
    void loadImage();

public:
    GLWidget(QWidget *parent);
    ~GLWidget();

protected:
    void paintGL();
    void initializeGL();
    void resizeGL(int w, int h);

private:
    void loadImageFromPath(const QString &path);
    std::shared_ptr<GlslShader> _shader;
    GLuint _texture_id;

};

#endif // GLWIDGET_H
