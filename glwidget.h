#ifndef GLWIDGET_H
#define GLWIDGET_H

//#include <glad/glad.h>
#include <QObject>
#include <QOpenGLWidget>

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent);
    ~GLWidget();

protected:
    void paintGL();
    void initializeGL();
    void resizeGL(int w, int h);

private:

};

#endif // GLWIDGET_H
