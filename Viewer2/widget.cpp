//#define GL_SILENCE_DEPRECATION
#include "widget.h"
#include "ui_widget.h"
#include "math.h"
#include <QMessageBox>

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
//     glFrustum(-1,1,-1,1,1,8);
     int min;
     int max;

get_max_min_frustum(&max, &min, obj);

if (qFabs(min) > max) {
        max = qFabs(min);
    } else if (max > qFabs(min)) {
        min = -max;
    }
min*=1.2;
max*=1.2;
//     glOrtho(max,min,max,min,max,min);
     glOrtho(min,max,min,max,min,max);
    if (obj.count_of_vertex < 10000) {
        glFrustum(max,min,max,min,max,min+20);
    } else {
    glFrustum(min,max,min,max,min,max);
    }
}




void Widget::filler() {
    char filename[50] = "cub.obj";
//    char filename[50] = "eyeball.obj";
//   char filename[50] = "Low-Poly-Racing-Car.obj";
//    char filename[50] = "Mercedes+Benz+GLS+580.obj";
//    char filename[50] = "cat.obj";
    printf("kek\n");
    obj.count_of_polygons = 0;
    obj.count_of_vertex = 0;
    if (!reading_counting(filename, &obj)) {
    parsing_matrix(filename, &obj);
//    if(a == 1) {
//        change_of_size_x(&obj, x);
//        change_of_size_y(&obj, y);
//        change_of_size_z(&obj, z);
//    } else if (a == 2) {

//    }

    } else {
        QMessageBox::warning(this, "Внимание","File not open");
    }

}


void Widget::shift(int code, double x, double y, double z) {
    if(code == 1) {
        change_of_size_x(&obj, x);
        change_of_size_y(&obj, y);
        change_of_size_z(&obj, z);
    } else if (code == 2) {
        move_x(&obj, x);
        move_y(&obj, y);
        move_z(&obj, z);
    } else if (code == 3) {
        turn_x(&obj, x);
        turn_y(&obj, y);
        turn_z(&obj, z);
    }
    update();
}

void Widget::paintGL() {
//    initializeGL();
    glTranslatef(0,0,-4);
    //на 10 тыщ чтоб пукан хотя бы у кошки отрисовался
//    double virus[obj.count_of_vertex * 10];
    double *vertex = (double *)calloc(obj.count_of_vertex*6, sizeof(double));
    unsigned int facetus[obj.count_of_polygons * 10];
//    unsigned int *facets = (unsigned int *)calloc(obj.count_of_polygons * 6, sizeof(unsigned int));

    for (int i = 0, k = 0; i < obj.matrix.rows; i++) {
        for (int j = 0; j < obj.matrix.columns; j++, k++) {
            vertex[k] = obj.matrix.matrix[i][j];
        }
    }
    for (int i = 0, k = 0;i < obj.count_of_polygons ; i++) {
        for (int j = 0; j < obj.poligons[i].numbers_of_vertexes_in_facets*2; j++, k++) {
             facetus[k] = obj.poligons[i].vertexes[j];
        }
    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(r1, g1, b1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glColor4f(0.1, 0.75, 0.3, 1); // цвет линий
    if (line_type) {
        glLineStipple(20, 0x3333);
        glEnable(GL_LINE_STIPPLE);
    }
    if (color_point == 1) {
    } else if (color_point == 2) {
        glPointSize(point_size);
        glEnable(GL_POINT_SMOOTH);
        glDisable(GL_POINT_SMOOTH);
    } else if (color_point == 3) {

    }
//    glClearColor(r1, g1, b1, 0);s
    glLineWidth(width);

    glVertexPointer(3, GL_DOUBLE, 0, vertex);
    glEnableClientState(GL_VERTEX_ARRAY);
    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonMode(GL_RED,GL_LINE);
//    double r = 1 ,g = 0, b = 0.5;
    //********************
//    r = 1; g = 0; b = 0.5;

        glColor4f(r, g, b, 1); // цвет линий
        glDrawElements(GL_POINTS, obj.count_of_polygons * 6, GL_UNSIGNED_INT, facetus);
        glColor4f(0.1, 0.75, 0.3, 1);
        glDrawElements(GL_LINES, obj.count_of_polygons * 6, GL_UNSIGNED_INT, facetus);

    glDisable(GL_POINT_SMOOTH);
    glDisable(GL_LINE_STIPPLE);



    glDisableClientState(GL_VERTEX_ARRAY);
    free(vertex);
//    free(facets);
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


