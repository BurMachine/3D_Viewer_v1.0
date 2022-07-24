//#define GL_SILENCE_DEPRECATION
#include "widget.h"
#include "ui_widget.h"
#include "math.h"

//Конструктор класса
Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::Widget)
{
    setWindowTitle("the game");
    setGeometry(400,200,800,600);
    filler();
}

Widget::~Widget()
{
    delete ui;
}

//инициализация
void Widget::initializeGL() {
//    разрешаем исопльзовать буфер opengl
    glEnable(GL_DEPTH_TEST);
}

void Widget::resizeGL(int w, int h) {
    glViewport(0,0,w,h);
//    задаем ортоганальную проекцию
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
//     glOrtho(-1,1,-1,1,1,2);
     glFrustum(-1,1,-1,1,1,8);

}




void Widget::filler() {
//    char filename[50] = "cub.obj";
    char filename[50] = "eyeball.obj";
//   char filename[50] = "hand.obj";
//    char filename[50] = "easyCube.obj";
//    char filename[50] = "cat.obj";

    obj.count_of_polygons = 0;
    obj.count_of_vertex = 0;
    reading_counting(filename, &obj);
    parsing_matrix(filename, &obj);

}

void Widget::paintGL() {
    initializeGL();
    glTranslatef(0,0,-5);
    //на 10 тыщ чтоб пукан хотя бы у кошки отрисовался
    double virus[obj.count_of_vertex * 4];
    unsigned int facetus[obj.count_of_polygons * 4];
    for (int i = 0, k = 0; i < obj.matrix.rows; i++) {
        for (int j = 0; j < obj.matrix.columns; j++, k++) {
            virus[k] = obj.matrix.matrix[i][j];
        }
    }
    for (int i = 0, k = 0;i < obj.count_of_polygons ; i++) {
        for (int j = 0; j < obj.poligons[i].numbers_of_vertexes_in_facets*2; j++, k++) {
             facetus[k] = obj.poligons[i].vertexes[j];
        }
    }




    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glColor4f(0.1, 0.75, 0.3, 1); // цвет линий


    glVertexPointer(3, GL_DOUBLE, 0, virus);
    glEnableClientState(GL_VERTEX_ARRAY);
    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonMode(GL_RED,GL_LINE);
    double r = 1 ,g = 0, b = 0.5;

        glColor4f(r, g, b, 1); // цвет линий
        glDrawElements(GL_POINTS, obj.count_of_polygons * 6, GL_UNSIGNED_INT, facetus);
        glColor4f(0.1, 0.75, 0.3, 1);
        glDrawElements(GL_LINES, obj.count_of_polygons * 6, GL_UNSIGNED_INT, facetus);

    glDisable(GL_POINT_SMOOTH);
    glDisable(GL_LINE_STIPPLE);


    glDisableClientState(GL_VERTEX_ARRAY);

}
//width - ширина
//heigth - высота
//vertex - вершина


void Widget::mousePressEvent(QMouseEvent* mo){
    mPos = mo->pos();
}
void Widget::mouseMoveEvent(QMouseEvent* mo){
    xRot= 1/M_PI*(mo->pos().y() - mPos.y());
    yRot= 1/M_PI*(mo->pos().x() - mPos.x());
    update();
}


