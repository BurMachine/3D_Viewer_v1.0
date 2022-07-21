//#define GL_SILENCE_DEPRECATION
#include "widget.h"
#include "ui_widget.h"
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
     glFrustum(-1,1,-1,1,1,20);

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
////    сколко переменных на одну вершину 3 тип glfloat ноль и адрес массива
//    glVertexPointer(3, GL_DOUBLE, 0, &array_coordinat);
////    разрешаем opengl использовать вершинный буфер
//    glEnableClientState(GL_VERTEX_ARRAY);
////    что рсуем ноль и сколько всего вершин
//    glDrawArrays(GL_TRIANGLES,0,3);
//    //    paint triangl
//    glBegin(GL_TRIANGLES);

//    glColor3d(0,0,0.5);
////    glVertex3d(1,0,-1.5);
////    glVertex3d(0,1,-1.5);
////    glVertex3d(1,1,-1.5);
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
// ЛИБО ОШИБКА В СИНТАКИСЕ СВ ЛЮБОМ СЛУЧАЕ НУНО ЗАНОВО ПРОСМОТРЕТЬ ВЕСЬ КОД НА ПРИ=ЕДМЕТ АРТЕФАКТОВ
void Widget::mousePressEvent(QMouseEvent* mo){
    mPos = mo->pos();
}
void Widget::mouseMoveEvent(QMouseEvent* mo){
    xRot= 1/M_PI*(mo->pos().y() - mPos.y());
    yRot= 1/M_PI*(mo->pos().x() - mPos.x());
    update();
}
void Widget::drawCube(float a){
    float ver_cub[] = {
        -a, -a, a,      a, -a, a,       a, a, a,      -a, a, a, // передняя
        a, -a, -a,      -a, -a, -a,       -a, a, -a,      a, a, -a, // задняя
        -a, -a, -a,      -a, -a, a,       -a, a, a,      -a, a, -a, // левая
        a, -a, a,      a, -a, -a,       a, a, -a,      a, a, a, // правая
        -a, -a, a,      a, -a, a,       a, -a, -a,      -a, -a, -a, // нижняя
        -a, a, a,      a, a, a,       a, a, -a,      -a, a, -a  // верхняя
    };
    float color_arr[] = {
        1,0,0,       1,0,0,       1,0,0,       1,0,0,
        0,0,1,       0,0,1,       0,0,1,       0,0,1,
        1,1,0,       1,1,0,       1,1,0,       1,1,0,
        0,1,1,       0,1,1,       0,1,1,       0,1,1,
        1,0,1,       1,0,1,       1,0,1,       1,0,1,
        1,0.5,0.5,   1,0.5,0.5,   1,0.5,0.5,   1,0.5,0.5
    };
    glVertexPointer(3, GL_FLOAT, 0, &ver_cub);
    glEnableClientState(GL_VERTEX_ARRAY);

    glColorPointer(3, GL_FLOAT, 0, &color_arr);
    glEnableClientState(GL_COLOR_ARRAY);

        glDrawArrays(GL_QUADS, 0, 24);

   glDisableClientState(GL_COLOR_ARRAY);
   glDisableClientState(GL_VERTEX_ARRAY);
}

