#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QDebug>
#include <QWheelEvent>
#include "quad.h"


class GLWidget : public QGLWidget
{
    Q_OBJECT
private:
     quad *square;
    void mainfunction(int iter, quad* A);
    int rec=0;

public:
    GLenum blend1 = GL_ZERO;
    GLenum blend2 = GL_SRC_ALPHA;


    int X=0, Y=0;
    int Width=200, Height=200;
    int winSizeW, winSizeH;

    void resizeGL(int w, int h);
    explicit GLWidget(QWidget *parent=0);
    GLenum choose_fact(QString type);

    void drawPicture(quad * _square, float col);
    void initializeGL();
    void paintGL();


//
private slots:
    void step(int step);
    void do_blend1(QString type);
    void do_blend2(QString type);

};

#endif // GLWIDGET_H
