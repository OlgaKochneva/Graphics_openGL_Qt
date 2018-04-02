#include "glwidget.h"
#include <QMouseEvent>
#include <cmath>
#include <QDebug>
#define binomial(n, i) (factorial(n) / (factorial(i) * factorial(n - i)))

GLWidget::GLWidget(QWidget *parent):
    QGLWidget(parent)
{
    points<<QPoint(50, 200)<<QPoint(270, 400)<<QPoint(350, 100)<<QPoint(490, 450)<<QPoint(550, 150)<<QPoint(650, 300);
    iSelected = -1;
}

void GLWidget::initializeGL()
{
    glClearColor(1, 1, 1, 1);//фон
}

void  GLWidget::drawLine(QPoint p1, QPoint p2) {
    glLineWidth(2);
    glColor4f(1.0f, 0.0f, 0.6f, 0.2f);//розовый
    glBegin(GL_LINE_STRIP);
    glVertex2f(p1.x(), p1.y());
    glVertex2f(p2.x(), p2.y());
    glEnd();
    glFlush();
}




void GLWidget::drawPicture(){
    //линия каркас
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//красный
    for(int i = 0; i < points.size(); i++)
    {
        glVertex2f(points[i].x(), points[i].y());
    }
    glEnd();
    //точки
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor4f(0.0f, 0.0f, 0.0f, 0.6f);//черный
    for(int i = 0; i < points.size(); i++)
    {
        glVertex2f(points[i].x(), points[i].y());
    }
    glEnd();
    //кривая

    QPoint p1 = points[0];
    for(double t = 0.0;t <= 1.0; t += 0.0001)
    {
        QPoint p2 = bezier(t);
        drawLine(p1, p2);
        p1 = p2;
    }

}


void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawPicture();
}

void GLWidget::resizeGL(int w, int h)
{
    this->winSizeW = w;
    this->winSizeH = h;
    glViewport(0,0,w,h);//выврд во всей области виджета
    glMatrixMode(GL_PROJECTION);//задает матрицу(проекций)
    glLoadIdentity();//заменяет текущую матрицу на единичную
    glOrtho(0.0, 700.0, 0.0, 500.0, 0, 700.0);//умножает текущую матрицу на ортогональную ей
    glMatrixMode(GL_MODELVIEW);//применяет послед операции в стек матричного представления
    glLoadIdentity();//заменяет текущую матрицу на единичную

}


double GLWidget::bernstein(int i, int n, double t)
{
    return binomial(n, i) * pow(t, i) * pow(1 - t, n - i);
}

QPoint GLWidget::bezier(double t)
{
    const int n = points.size() - 1;
    QPointF sum;

    for (int i = 0; i <= n; i++)
        sum += QPointF(points[i]) * bernstein(i, n, t);
    return sum.toPoint();
}

double GLWidget::factorial(double n)
{
    double fact = 1.0;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{

    if (event->button() != Qt::LeftButton)
        return;
    for (int i = 0; i <points.size(); i++) {

        if (qAbs(points[i].x() - 700*event->pos().x()/winSizeW) < 7 && qAbs(points[i].y() -  500*(winSizeH-event->pos().y())/winSizeH) < 10) {
            if (event->button() == Qt::LeftButton) {
                iSelected = i;
                this->updateGL();
            }
            return;
        }
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    //присваиваем значение куда сместили
    if ((event->buttons() & Qt::LeftButton) == Qt::LeftButton && iSelected >= 0) {
        QPoint newcoord(700*event->pos().x()/winSizeW, 500*(winSizeH-event->pos().y())/winSizeH);
        points[iSelected] = newcoord;
        this->updateGL();
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    //когда отпустили мышь чтоб ничего не было выбрано
    if (event->button() == Qt::LeftButton) {
        iSelected = -1;
        this->updateGL();
    }
}





