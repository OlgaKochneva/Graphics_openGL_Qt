#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QPoint>
#include <QList>
#include <QStack>


class GLWidget : public QGLWidget
{
    Q_OBJECT
private:
    QList<QPoint> points;
    int iSelected;
    QPoint bezier(double t);
    double bernstein(int i, int n, double t);
    double factorial(double n);

protected:

    void mousePressEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);


public:
    void drawLine(QPoint p1, QPoint p2);
    int winSizeW, winSizeH;
    void resizeGL(int w, int h);
    explicit GLWidget(QWidget *parent=0);
    void drawPicture();
    void initializeGL();
    void paintGL();


};

#endif // GLWIDGET_H
