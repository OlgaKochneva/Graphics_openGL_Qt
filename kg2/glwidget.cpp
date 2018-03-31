#include "glwidget.h"


GLWidget::GLWidget(QWidget *parent):
    QGLWidget(parent)
{

}

void GLWidget::initializeGL()
{
    glClearColor(1, 1, 1, 1);//фон
}

void GLWidget::drawPicture(){
    QString type = this->shape;
    if(type == "GL_POINTS")
    {
       points();
        return;
    }
    if(type == "GL_LINES")
    {
        lines();
        return;
    }
    if(type == "GL_LINE_STRIP")
    {
       linestrip();
        return;
    }
    if(type == "GL_LINE_LOOP")
    {
        lineloop();

        return;
    }
    if(type == "GL_TRIANGLES")
    {
        triangles();

        return;
    }
    if(type == "GL_TRIANGLE_STRIP")
    {
        trianglestrip();

        return;
    }
    if(type == "GL_TRIANGLE_FAN")
    {
        trianglefan();
        return;
    }
    if(type == "GL_QUADS")
    {
        quads();
        return;
    }
    if(type == "GL_QUAD_STRIP")
    {
        quadstrip();
        return;
    }
    if(type == "GL_POLYGON")
    {
       polygon();
        return;
    }

}


void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
   glEnable(GL_SCISSOR_TEST);
   glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);

    glBlendFunc(this->blend1, this->blend2);
    glAlphaFunc(this->func, this->ref);
    glScissor(this->X * this->winSizeW/100, this->Y*this->winSizeH /100, this->winSizeW*this->Width/100, this->winSizeH*this->Height/100) ;
    drawPicture();
    glDisable(GL_BLEND);//
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_SCISSOR_TEST);
 }



void GLWidget::changeShapePicture(QString type)
{
    this->shape = type;
    this->updateGL();

}
void GLWidget::do_blend1(QString type)
{
    this->blend1 = choose_fact(type);
    this->updateGL();

}
void GLWidget::do_blend2(QString type)
{
    this->blend2 = choose_fact(type);
    this->updateGL();

}
void GLWidget::do_atest(QString type)
{
    this->func = choose_atest(type);
    this->updateGL();

}

void GLWidget::do_atest2(int val)
{
    this->ref = val/100.0f;
    this->updateGL();

}
void GLWidget::cut_x(int val){

    this->X=val;
    this->updateGL();
}

void GLWidget::cut_y(int val){
    this->Y=val;
    this->updateGL();
}

void GLWidget::change_height(int val){
    this->Height=val;
    this->updateGL();
}

void GLWidget::change_width(int val){
    this->Width=val;
    this->updateGL();
}
void GLWidget::resizeGL(int w, int h)
{
    this->winSizeW = w;
    this->winSizeH =h;
    glViewport(0,0,w,h);//выврд во всей области виджета
    glMatrixMode(GL_PROJECTION);//задает матрицу(проекций)
    glLoadIdentity();//заменяет текущую матрицу на единичную
    glOrtho(0.0, 200.0, 0.0, 100.0, 0, 200.0);//умножает текущую матрицу на ортогональную ей
    glMatrixMode(GL_MODELVIEW);//применяет послед операции в стек матричного представления
    glLoadIdentity();//заменяет текущую матрицу на единичную

}
GLenum GLWidget::choose_atest(QString type){
    if(type == "GL_NEVER") return GL_NEVER;
    if(type == "GL_EQUAL")return GL_EQUAL;
    if(type == "GL_LEQUAL")return GL_LEQUAL;
    if(type == "GL_GREATER")return GL_GREATER;
    if(type == "GL_NOTEQUAL")return GL_NOTEQUAL;
    if(type == "GL_GEQUAL")return GL_GEQUAL;
    if(type == "GL_ALWAYS")return GL_ALWAYS;
    if(type == "GL_LESS") return GL_LESS;
}

GLenum GLWidget::choose_fact(QString type){
    if(type=="GL_ZERO") return GL_ZERO;
    if(type=="GL_ONE") return GL_ONE;
    if(type=="GL_DST_COLOR") return GL_DST_COLOR;
    if(type=="GL_ONE_MINUS_DST_COLOR") return GL_ONE_MINUS_DST_COLOR;
    if(type=="GL_SRC_ALPHA") return GL_SRC_ALPHA;
    if(type=="GL_ONE_MINUS_DST_ALPHA") return GL_ONE_MINUS_DST_ALPHA;
    if(type=="GL_SRC_ALPHA_SATURATE") return GL_SRC_ALPHA_SATURATE;
    if(type=="GL_SRC_COLOR") return GL_SRC_COLOR;
    if(type=="GL_ONE_MINUS_SRC_COLOR") return GL_ONE_MINUS_SRC_COLOR;
    if(type=="GL_ONE_MINUS_SRC_ALPHA") return GL_ONE_MINUS_SRC_ALPHA;
    if(type=="GL_DST_ALPHA") return GL_DST_ALPHA;
}

void GLWidget:: points()
{

    glPointSize(6);
    glBegin(GL_POINTS);

    glColor4f(0.2f, 0.0f, 0.58f, 0.2f);//синий
    glVertex2f(50, 50);
    glColor4f(1.0f, 0.0f, 0.6f, 0.4f);//розовый
    glVertex2f( 100, 45);
    glColor4f(0.0f, 1.0f, 0.0f, 0.6f);//зеленый
    glVertex2f(150, 90);
    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);//черный
    glVertex2f( 190, 65);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//красный
    glVertex2f(30, 80);
    glEnd();
}
void GLWidget::lines()
{
    glLineWidth(4);
    glBegin(GL_LINES);

    glColor4f(1.0f, 0.0f, 0.6f, 0.2f);//розовый
    glVertex2f( 100, 45);
    glColor4f(0.0f, 1.0f, 0.0f, 0.4f);//зеленый
    glVertex2f(150, 90);

    glColor4f(0.0f, 0.0f, 0.0f, 0.6f);//черный
    glVertex2f( 190, 65);
    glColor4f(1.0f, 0.0f, 0.0f, 0.8f);//красный
    glVertex2f(30, 80);

    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);//черный
    glVertex2f(10, 10);
    glVertex2f( 150, 50);
    glEnd();
}

void GLWidget::linestrip()
{
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glColor4f(1.0f, 0.0f, 0.6f, 1.0f);//розовый
    glVertex2f( 100, 45);
    glColor4f(0.0f, 1.0f, 0.0f, 0.8f);//зеленый
    glVertex2f(150, 90);

    glColor4f(0.0f, 0.0f, 0.0f, 0.6f);//черный
    glVertex2f( 190, 65);
    glColor4f(1.0f, 0.0f, 0.0f, 0.4f);//красный
    glVertex2f(30, 80);

    glColor4f(0.0f, 0.0f, 0.0f, 0.2f);//черный
    glVertex2f(10, 10);
    glVertex2f( 150, 50);
    glEnd();
}

void GLWidget::lineloop()
{
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);

    glColor4f(1.0f, 0.0f, 0.6f, 1.0f);//розовый
    glVertex2f( 100, 45);
    glColor4f(0.0f, 1.0f, 0.0f, 0.8f);//зеленый
    glVertex2f(150, 90);
    glColor4f(0.0f, 0.0f, 0.0f, 0.6f);//черный
    glVertex2f( 190, 65);
    glColor4f(1.0f, 0.0f, 0.0f, 0.4f);//красный
    glVertex2f(30, 80);
    glColor4f(0.0f, 0.0f, 0.0f, 0.2f);//черный
    glVertex2f(10, 10);
    glColor4f(1.0f, 1.0f, 0.0f, 0.1f);//желтый
    glVertex2f( 150, 50);
    glEnd();
}

void GLWidget::triangles()
{
    glBegin(GL_TRIANGLES);

    glColor4f(1.0f, 0.0f, 0.6f, 1.0f);//розовый
    glVertex2f( 100, 45);
    glColor4f(0.0f, 1.0f, 0.0f, 0.8f);//зеленый
    glVertex2f(150, 90);
    glColor4f(0.0f, 0.0f, 0.0f, 0.6f);//черный
    glVertex2f( 190, 65);

    glColor4f(1.0f, 0.0f, 0.0f, 0.4f);//красный
    glVertex2f(30, 80);
    glColor4f(0.0f, 0.0f, 0.0f, 0.2f);//черный
    glVertex2f(10, 10);
    glColor4f(1.0f, 1.0f, 0.0f, 0.1f);//желтый
    glVertex2f( 150, 50);

    glEnd();
}

void GLWidget::trianglestrip()
{
    glBegin(GL_TRIANGLE_STRIP);

    glColor4f(1.0f, 0.0f, 0.6f, 1.0f);//розовый
    glVertex2f( 100, 45);
    glColor4f(0.0f, 1.0f, 0.0f, 0.8f);//зеленый
    glVertex2f(150, 90);
    glVertex2f( 190, 65);

    glColor4f(1.0f, 0.0f, 0.0f, 0.4f);//красный
    glVertex2f(30, 80);
    glColor4f(1.0f, 1.0f, 0.0f, 0.1f);//желтый

    glEnd();
}
void GLWidget::trianglefan()
{
    glBegin(GL_TRIANGLE_FAN);

    glColor4f(1.0f, 0.0f, 0.6f, 0.4f);//розовый
    glVertex2f( 100, 45);
    glVertex2f(50, 50);

    glColor4f(0.0f, 1.0f, 0.0f, 0.6f);//зеленый
    glVertex2f(150, 90);
    glVertex2f( 190, 65);

    glEnd();
}
void GLWidget::quads()
{
    glBegin(GL_QUADS);

    glColor4f(1.0f, 0.0f, 0.6f, 0.1f);//розовый
    glVertex2f( 10, 10);
    glVertex2f(10, 20);
    glVertex2f( 20, 20);
    glVertex2f(20, 10);

    glColor4f(0.0f, 0.0f, 0.0f, 0.1f);//черный
    glVertex2f( 100, 45);
    glVertex2f(50, 50);
    glVertex2f(70, 60);
    glVertex2f( 110, 60);

    glColor4f(0.2f, 0.0f, 0.58f, 0.1f);//синий
    glVertex2f(90, 70);
    glVertex2f(150, 90);
    glVertex2f( 190, 65);
    glVertex2f( 100, 45);

    glEnd();
}
void GLWidget::quadstrip()
{
    glBegin(GL_QUAD_STRIP);

    glColor4f(0.0f, 0.0f, 0.0f, 0.1f);//черный
    glVertex2f( 30, 10);
    glColor4f(1.0f, 0.0f, 0.6f, 0.9f);//розовый
    glVertex2f(10, 40);
    glVertex2f( 30, 70);
    glVertex2f(60, 70);

    glColor4f(0.0f, 0.0f, 0.0f, 0.1f);//черный
    glVertex2f(80, 40);
    glVertex2f(60, 10);

    glEnd();
}
void GLWidget::polygon()
{
    glBegin(GL_POLYGON);

    glColor4f(1.0f, 0.0f, 0.6f, 0.9f);//розовый
    glVertex2f( 30, 10);
    glVertex2f(10, 40);
    glVertex2f( 30, 70);
    glVertex2f(60, 70);

    glColor4f(0.0f, 0.0f, 0.0f, 0.1f);//черный
    glVertex2f(80, 40);
    glVertex2f(60, 10);

    glEnd();
}
