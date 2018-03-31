#include "glwidget.h"


GLWidget::GLWidget(QWidget *parent):
    QGLWidget(parent)
{

}

void GLWidget::initializeGL()
{
    glClearColor(1, 1, 1, 1);//фон
}

void GLWidget::drawPicture(quad* _square, float col){
    glBegin(GL_QUADS);

    glColor4f(0.360f, 0.09f, 0.58f, col*0.1f);//фиолетовый
    glVertex2f(_square->getx()-_square->getsize(), _square->gety()-_square->getsize());
    glVertex2f(_square->getx()-_square->getsize(), _square->gety()+_square->getsize());
    glVertex2f( _square->getx()+_square->getsize(), _square->gety()+_square->getsize());
    glVertex2f(_square->getx()+_square->getsize(), _square->gety()-_square->getsize());
    glEnd();
    return;

}


void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);

    glBlendFunc(this->blend1, this->blend2);


    square = new quad(this->Width/2.0,this->Height/2.0, 25.0f,0);
    mainfunction(0,square);

    //QString str = QString::number(this->Width/2.0);
    //qDebug()<<str;
    glDisable(GL_BLEND);//

}

void GLWidget:: mainfunction(int iter, quad* A){
    if(iter<rec)
    {
        if(A->getf()==0)
        {
            drawPicture(A,iter);
            quad *D = new quad(A->getx(),A->gety()-1.5f*A->getsize(),A->getsize()/2.0f, -1);
            drawPicture(D,iter);
            quad *L = new quad(A->getx()-1.5f*A->getsize(),A->gety(),A->getsize()/2.0f, -2);
            drawPicture(L,iter);
            quad *R = new quad(A->getx()+1.5f*A->getsize(),A->gety(),A->getsize()/2.0f,2);
            drawPicture(R,iter);
            quad *U = new quad(A->getx(),A->gety()+1.5f*A->getsize(),A->getsize()/2.0f,1);
            drawPicture(U,iter);
            iter++;
            mainfunction(iter, D);
            mainfunction(iter, L);
            mainfunction(iter, R);
            mainfunction(iter, U);
        }
        else
        {
            if(A->getf()==-1){
                quad *D = new quad(A->getx(),A->gety()-1.5f*A->getsize(),A->getsize()/2.0f, -1);
                drawPicture(D,iter);
                quad *L = new quad(A->getx()-1.5f*A->getsize(),A->gety(),A->getsize()/2.0f, -2);
                drawPicture(L,iter);
                quad *R = new quad(A->getx()+1.5f*A->getsize(),A->gety(),A->getsize()/2.0f,2);
                drawPicture(R,iter);
                iter++;
                mainfunction(iter, D);
                mainfunction(iter, L);
                mainfunction(iter, R);
            }
            if(A->getf()==-2){
                quad *D = new quad(A->getx(),A->gety()-1.5f*A->getsize(),A->getsize()/2.0f, -1);
                drawPicture(D,iter);
                quad *L = new quad(A->getx()-1.5f*A->getsize(),A->gety(),A->getsize()/2.0f, -2);
                drawPicture(L,iter);
                quad *U = new quad(A->getx(),A->gety()+1.5f*A->getsize(),A->getsize()/2.0f,1);
                drawPicture(U,iter);
                iter++;
                mainfunction(iter, D);
                mainfunction(iter, L);
                mainfunction(iter, U);
            }
            if(A->getf()==1){

                quad *L = new quad(A->getx()-1.5f*A->getsize(),A->gety(),A->getsize()/2.0f, -2);
                drawPicture(L,iter);
                quad *R = new quad(A->getx()+1.5f*A->getsize(),A->gety(),A->getsize()/2.0f,2);
                drawPicture(R,iter);
                quad *U = new quad(A->getx(),A->gety()+1.5f*A->getsize(),A->getsize()/2.0f,1);
                drawPicture(U,iter);
                iter++;
                mainfunction(iter, L);
                mainfunction(iter, R);
                mainfunction(iter, U);

            }
            if(A->getf()==2){
                quad *D = new quad(A->getx(),A->gety()-1.5f*A->getsize(),A->getsize()/2.0f, -1);
                drawPicture(D,iter);
                quad *R = new quad(A->getx()+1.5f*A->getsize(),A->gety(),A->getsize()/2.0f,2);
                drawPicture(R,iter);
                quad *U = new quad(A->getx(),A->gety()+1.5f*A->getsize(),A->getsize()/2.0f,1);
                drawPicture(U,iter);
                iter++;
                mainfunction(iter, D);
                mainfunction(iter, R);
                mainfunction(iter, U);

            }

        }
    }
    if(iter==0)
        drawPicture(A,1);
    return;
}

void GLWidget:: step(int step)
{
    this->rec=step;
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


void GLWidget::resizeGL(int w, int h)
{

   this->winSizeW = w;
    this->winSizeH =h;
    glViewport(0,0,w,h);//выврд во всей области виджета
    glMatrixMode(GL_PROJECTION);//задает матрицу(проекций)
    glLoadIdentity();//заменяет текущую матрицу на единичную
    glOrtho(0.0, 200.0, 0.0, 200.0, 0, 200.0);//умножает текущую матрицу на ортогональную ей
    glMatrixMode(GL_MODELVIEW);//применяет послед операции в стек матричного представления
    glLoadIdentity();//заменяет текущую матрицу на единичную
    glMatrixMode(GL_MODELVIEW);

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

