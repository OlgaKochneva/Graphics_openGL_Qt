#ifndef PRIMITIVES_H
#define PRIMITIVES_H


class primitives : public QGLWidget
{
    Q_OBJECT
    private:
        QString ComboBox_type="GL_POINTS";
    public:
        explicit GLWidget(QWidget *parent=0);
        void initializeGL();
        void paintGL();
        void resizeGL(int w, int h);
    //
    private slots:
        void changeShapePicture(QString type);
    };

#endif // PRIMITIVES_H
