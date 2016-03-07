#-------------------------------------------------
#
# Project created by QtCreator 2015-12-31T15:45:11
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = FreeImageOpenGL
TEMPLATE = app

INCLUDEPATH += $$_PRO_FILE_PWD_/include
win32: LIBS += $$_PRO_FILE_PWD_/lib64/FreeImage.lib $$_PRO_FILE_PWD_/lib64/FreeImagePlus.lib
unix: LIBS += -L$$_PRO_FILE_PWD_/lib64

CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
CONFIG(debug, debug|release): DESTDIR = $$OUT_PWD/debug

DllFiles.path = $$DESTDIR
DllFiles.files += $$files(dll/*.dll)

INSTALLS += DllFiles

SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    fimage.cpp \
    include/src/glad.c

HEADERS  += mainwindow.h \
    glwidget.h \
   # image.h \
    fimage.h \
    include/glad/glad.h

FORMS    += mainwindow.ui
