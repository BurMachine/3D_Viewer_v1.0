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
#include "../src/gryffind_dev/afinn_translation.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QOpenGLWidget
{
    Q_OBJECT
private:
    double xRot, yRot, zRot;
    QPoint mPos;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void filler(int a, double x, double y, double z);

    Data obj;
private:
    Ui::Widget *ui;


};
#endif // WIDGET_H

