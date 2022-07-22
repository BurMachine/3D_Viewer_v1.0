//#define GL_SILENCE_DEPRECATION
#include "widget.h"
#include "ui_widget.h"
#include "math.h"
extern "C" double *translator(double array_coordinat[], int len);

//Конструктор класса
Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::Widget)
{
//    ui->setupUi(this);
    setWindowTitle("the game");
    setGeometry(400,200,800,600);
//    z = 0;
////    соединим таймер со слотом
//    connect(&tmr,SIGNAL(timeout()), this, SLOT (changeZ()));
////    укажем задержку в 100 мс
//    tmr.start(100);
}

Widget::~Widget()
{
    delete ui;
}

//инициализация
void Widget::initializeGL() {
//    initializeOpenGLFunctions();
//    разрешаем исопльзовать буфер opengl
    glEnable(GL_DEPTH_TEST);
}

void Widget::resizeGL(int w, int h) {
    glViewport(0,0,w,h);
//    задаем ортоганальную проекцию
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
//     glOrtho(-1,1,-1,1,1,2);
     glFrustum(-3,3,-3,3,1,30);
//     glFrustum(-1,1,-1,1,1,30);

}
//double  array_coordinat[] = {1,0,-1.5,
//                             0,1,-1.5,
//                             1,1,-1.5};
//double  array_coordinat[] = {0,0,-1.5,
//                             1,0,-1.5,
//                             0,1,-1.5};
//рисование
void Widget:: paintGL() {
    glClearColor(0,1,0,0);
    //очищаем буфер цвета и глубины
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
//    загружаем в стек единичную матрицу
    glLoadIdentity();
//    меняем направление осей x y
//    glRotated(90,0,0,1);
//    перемещает по оси z
    glTranslatef(0,0,-2);
    glRotatef(xRot,1,0,0);
    glRotatef(yRot,0,1,0);
    drawCube(0.4);
//    drawCube_2();
//    drawCube_3();
//    drawCube_kube();
////    сколко переменных на одну вершину 3 тип glfloat ноль и адрес массива
//    glVertexPointer(3, GL_DOUBLE, 0, &array_coordinat);
////    разрешаем opengl использовать вершинный буфер
//    glEnableClientState(GL_VERTEX_ARRAY);
////    что рсуем ноль и сколько всего вершин
//    glDrawArrays(GL_TRIANGLES,0,3);
//    //    paint triangl
//    glBegin(GL_QUADS);

//    glColor3d(0,0,0.5);
//    glVertex3d(1,0,-1.5);
//    glVertex3d(0,1,-1.5);
//    glVertex3d(1,1,-1.5);

//    glBegin(GL_LINES);
//    glEnd();

}
//width - ширина
//heigth - высота
//vertex - вершина

//определеним слот
//void Widget::changeZ(){
//    z -= 0.01;
//    qDebug() << z;
//    update();
//}
void Widget::mousePressEvent(QMouseEvent* mo){
    mPos = mo->pos();
}
void Widget::mouseMoveEvent(QMouseEvent* mo){
    xRot= 1/M_PI*(mo->pos().y() - mPos.y());
    yRot= 1/M_PI*(mo->pos().x() - mPos.x());
    update();
}
void Widget::drawCube_2() {
//        glBegin(GL_QUADS);
        glColor3d(0,0,0.5);
        glBegin(GL_LINES);
     glVertex3d(1.000000, -1.000000, -1.000000);
    glBegin(GL_LINES);
    glVertex3d(0.000000, -1.000000, 1.000000);
    glBegin(GL_LINES);
    glVertex3d( -1.000000, -1.000000, 1.000000);
    glBegin(GL_LINES);
   glVertex3d (-1.000000, -1.000000, -1.000000);
   glBegin(GL_LINES);
    glVertex3d(1.000000, 1.000000, -0.999999);
    glBegin(GL_LINES);
   glVertex3d (0.999999, 1.000000, 1.000001);
   glBegin(GL_LINES);
   glVertex3d (-1.000000, 1.000000, 1.000000);
   glBegin(GL_LINES);
   glVertex3d (-1.000000, 1.000000, -1.000000);


    glEnd();
}

void Widget::drawCube_3() {
    float vretices[] = {
        0,0,
        1,0,
        1,1,
        0,1
    };
    float color_arr[] = {1,0,0,   0,1,0,    0,0,1,  1,1,0};
    glVertexPointer(2, GL_FLOAT, 0, &vretices);
    glEnableClientState(GL_VERTEX_ARRAY);
    // количество координат на точку,
    glColorPointer(3, GL_FLOAT, 0, &color_arr);
    glEnableClientState(GL_COLOR_ARRAY);
    //   тип примитива, с какой верщины нужно рисовать, количество вершин
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

   glDisableClientState(GL_COLOR_ARRAY);
   glDisableClientState(GL_VERTEX_ARRAY);
}
//struct{
//    float x,y,z;
//} enemy[40];
void Widget::drawCube_kube() {
    float vretices[] = {
        0,0,0,
        0,1,0,
        1,1,0,
        1,0,0,
        0,0,1,
        0,1,1,
        1,1,1,
        1,0,1,
    };
    float kubeint[] = {
        0,1,2,
        2,3,0,
        4,5,6,
        6,7,4,
        3,2,5,
        6,7,3,
        0,1,5,
        5,4,0,
        1,2,6,
        6,5,1,
        0,3,7,
        7,4,0,
    };
//    for(int i = 0; i < 40; i++){
//        enemy[i].x = arc4random() % 40;
//        enemy[i].y = arc4random() % 40;
//        enemy[i].z = arc4random() % 40;
//    }
//    float color_arr[] = {1,0,0,   0,1,0,    0,0,1,  1,1,0};
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &vretices);

    // количество координат на точку,
//    glColorPointer(1, GL_FLOAT, 0, &color_arr);
//    glEnableClientState(GL_COLOR_ARRAY);
    //   тип примитива, с какой верщины нужно рисовать, количество вершин
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, kubeint);

//   glDisableClientState(GL_COLOR_ARRAY);
   glDisableClientState(GL_VERTEX_ARRAY);
}
//double  array_coordinat[] = {0,0,-1.5,
//                             1,0,-1.5,
//                             0,1,-1.5};

//double  array_coordinat[] = {0.500000,
//                             -0.500000,
//                             -0.500000,
//                             0.500000,
//                             -0.500000,
//                             0.500000,
//                             -0.500000,
//                             -0.500000,
//                             0.500000,
//                             -0.500000,
//                             -0.500000,
//                             -0.500000,
//                             0.500000,
//                             0.500000,
//                             -0.499999,
//                             0.499999,
//                             0.500000,
//                             0.500000,
//                             -0.500000,
//                             0.500000,
//                             0.500000,
//                             -0.500000,
//                             0.500000,
//                             -0.500000};

//double  array_coordinat[] = {1.000000, -1.000000, -1.000000,
//1.000000, -1.000000, 1.000000,
// -1.000000, -1.000000, 1.000000,
//-1.000000, -1.000000, -1.000000,
//-1.000000, 1.000000, -1.000000,
//1.000000, 1.000000, -0.999999,
//0.999999, 1.000000, 1.000001,
//-1.000000, 1.000000, 1.000000
//};
//float color_arr[] = {}
void Widget::drawCube(float a){
//    float ver_cub[] = {
//        -a, -a, a,      a, -a, a,       a, a, a,      -a, a, a, // передняя
//        a, -a, -a,      -a, -a, -a,       -a, a, -a,      a, a, -a, // задняя
//        -a, -a, -a,      -a, -a, a,       -a, a, a,      -a, a, -a, // левая
//        a, -a, a,      a, -a, -a,       a, a, -a,      a, a, a, // правая
//        -a, -a, a,      a, -a, a,       a, -a, -a,      -a, -a, -a, // нижняя
//        -a, a, a,      a, a, a,       a, a, -a,      -a, a, -a  // верхняя
//    };
//    int len = sizeof(array_coordinat) / sizeof(array_coordinat[0]);
//    double *new_array = translator(array_coordinat, len);
    a++;

    double  array_coordinat[] = {1.000000, -1.000000, -1.000000,
    1.000000, -1.000000, 1.000000,
     -1.000000, -1.000000, 1.000000,
    -1.000000, -1.000000, -1.000000,
    1.000000, 1.000000, -0.999999,
    0.999999, 1.000000, 1.000001,
    -1.000000, 1.000000, 1.000000,
    -1.000000, 1.000000, -1.000000};
    float color_arr[] = {
        1,0,0,       1,0,0,       1,0,0,       1,0,0,
        0,0,1,       0,0,1,       0,0,1,       0,0,1,
        1,1,0,       1,1,0,       1,1,0,       1,1,0,
        0,1,1,       0,1,1,       0,1,1,       0,1,1,
        1,0,1,       1,0,1,       1,0,1,       1,0,1,
        1,0.5,0.5,   1,0.5,0.5,   1,0.5,0.5,   1,0.5,0.5
    };
    glVertexPointer(3, GL_FLOAT, 0, &array_coordinat);
    glEnableClientState(GL_VERTEX_ARRAY);
    // количество координат на точку,
    glColorPointer(3, GL_FLOAT, 0, &color_arr);
    glEnableClientState(GL_COLOR_ARRAY);
    //   тип примитива, с какой верщины нужно рисовать, количество вершин
        glDrawArrays(GL_POINTS, 0, 8);
    glDrawElements(GL_LINES, ,GL_UNSIGNED_INT,)
   glDisableClientState(GL_COLOR_ARRAY);
   glDisableClientState(GL_VERTEX_ARRAY);
}

