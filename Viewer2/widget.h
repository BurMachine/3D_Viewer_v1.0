#ifndef WIDGET_H
#define WIDGET_H
#define GL_SILENCE_DEPRECATION
#include <QWidget>
#include <QtOpenGLWidgets/qopenglwidget.h>
#include <QOpenGLFunctions>
#include <QGuiApplication>
#include <QTimer>
#include <QMouseEvent>

extern "C" {
#include "../src/gryffind_dev/parsing.h"
#include "../src/gryffind_dev/matrix/s21_matrix.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QOpenGLWidget
{
    Q_OBJECT
private:
//    double z;
    double xRot, yRot, zRot;
    QPoint mPos;
    QTimer tmr;
//    void drawCube(float a);
//    void drawCube_2();
//    void drawCube_3();
//    void drawCube_kube();
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void drawCube_23();
//    void print_matrix_new(matrix_t mat);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;

//public slots:
//    void changeZ();
};
#endif // WIDGET_H
//, protected QOpenGLFunctions
