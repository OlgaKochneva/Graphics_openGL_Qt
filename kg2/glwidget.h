#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
private:

public:
    QString shape = "GL_POINTS";
    GLenum blend1 = GL_ZERO;
    GLenum blend2 = GL_ZERO;
    GLenum func = GL_ALWAYS;
    //GLint x =  -1;
   // GLint y = -1;
    //GLsizei width = 1;
    //GLsizei height = 1;
    GLclampf ref = 0;

    int X=0, Y=0;
    int Width=200, Height=100;
    int winSizeW, winSizeH;

    void resizeGL(int w, int h);
    explicit GLWidget(QWidget *parent=0);
    GLenum choose_fact(QString type);
    GLenum choose_atest(QString type);
    void points();
    void lines();
    void linestrip();
    void lineloop();
    void triangles();
    void trianglestrip();
   void trianglefan();
    void quads();
   void quadstrip();
   void polygon();
    void drawPicture();
    void initializeGL();
    void paintGL();
    void do_update();

//
private slots:
    void changeShapePicture(QString type);
    void do_blend1(QString type);
    void do_blend2(QString type);
    void do_atest(QString type);
    void do_atest2(int val);
    void cut_x(int val);
    void cut_y(int val);
    void change_height(int val);
    void change_width(int val);

};

#endif // GLWIDGET_H
