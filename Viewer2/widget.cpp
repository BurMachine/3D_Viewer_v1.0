//#define GL_SILENCE_DEPRECATION
#include "widget.h"
#include "ui_widget.h"
#include "math.h"
//extern "C" double *translator(double array_coordinat[], int len);
//extern "C" int reading_counting(char *file_name, Data *obj);
//extern "C" int parsing_matrix(char *file_name, Data *obj);
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
    connect(&tmr,SIGNAL(timeout()), this, SLOT (changeZ()));
    filler();
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
//     glFrustum(-1,3,-3,3,1,30);
     glFrustum(-1,1,-1,1,1,8);

}




void Widget::filler() {
//    char filename[50] = "cub.obj";
    char filename[50] = "eyeball.obj";
//        char filename[50] = "hand.obj";


//    char filename[50] = "easyCube.obj";
//    char filename[50] = "cat.obj";
    obj.count_of_polygons = 0;
    obj.count_of_vertex = 0;
    reading_counting(filename, &obj);
    parsing_matrix(filename, &obj);
//        for (int i = 0; i < obj.matrix.rows; i++) {
//            for (int j = 0; j < obj.matrix.columns; j++) {
//                qDebug() << obj.matrix.matrix[i][j];
//            }
//    //        printf("\n");
//        }

//        for (int i = 0;i < obj.count_of_polygons ; i++) {
//            for (int j = 0; j < obj.poligons[i].numbers_of_vertexes_in_facets*2; j++) {
//                 qDebug() << obj.poligons[i].vertexes[j];
//            }
//        }
}

void Widget::paintGL() {
    initializeGL();
    glTranslatef(0,0,-5);
    //на 10 тыщ чтоб пукан хотя бы у кошки отрисовался
    double virus[obj.count_of_vertex * 4];
//    calloc(obj.count_of_vertex, sizeof(double))
    unsigned int facetus[obj.count_of_polygons * 4];
    for (int i = 0, k = 0; i < obj.matrix.rows; i++) {
        for (int j = 0; j < obj.matrix.columns; j++, k++) {
            virus[k] = obj.matrix.matrix[i][j];
        }
//        printf("\n");
    }
    for (int i = 0, k = 0;i < obj.count_of_polygons ; i++) {
        for (int j = 0; j < obj.poligons[i].numbers_of_vertexes_in_facets*2; j++, k++) {
             facetus[k] = obj.poligons[i].vertexes[j];
        }
    }

    double ver[] = {
        1.000000, -1.000000, -1.000000,
        1.000000, -1.000000, 1.000000,
        -1.000000, -1.000000, 1.000000,
        -1.000000, -1.000000, -1.000000,
        1.000000, 1.000000, -0.999999,
        0.999999, 1.000000, 1.000001,
        -1.000000, 1.000000, 1.000000,
        -1.000000, 1.000000, -1.000000
        };
    unsigned int facets[] = {
        1, 2, 2, 3, 3, 1,
        7, 6, 6, 5, 5, 7,
        4, 5, 5, 1, 1, 4,
        5, 6, 6, 2, 2, 5,
        2, 6, 6, 7, 7, 2,
        0, 3, 3, 7, 7, 0,
        0, 1, 1, 3, 3, 0,
        4, 7, 7, 5, 5, 4,
        0, 4, 4, 1, 1, 0,
        1, 5, 5, 2, 2, 1,
        3, 2, 2, 7, 7, 3,
        4, 0, 0, 7, 7, 4
    };


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glColor4f(0.1, 0.75, 0.3, 1); // цвет линий

//    glVertexPointer(3, GL_DOUBLE, 0, obj.matrix.matrix);
    glVertexPointer(3, GL_DOUBLE, 0, virus);
    glEnableClientState(GL_VERTEX_ARRAY);
    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonMode(GL_RED,GL_LINE);
    double r = 1 ,g = 0, b = 0.5;

        glColor4f(r, g, b, 1); // цвет линий
//        glDrawElements(GL_POINTS, 72, GL_UNSIGNED_INT, obj.poligons);
        glDrawElements(GL_POINTS, obj.count_of_polygons * 6, GL_UNSIGNED_INT, facetus);
        glColor4f(0.1, 0.75, 0.3, 1);
//       glDrawElements(GL_LINES, 72, GL_UNSIGNED_INT, obj.poligons);
        glDrawElements(GL_LINES, obj.count_of_polygons * 6, GL_UNSIGNED_INT, facetus);

//    glDrawElements(GL_TRIANGLES, massives.size_polygons / 6, GL_UNSIGNED_INT, massives.polygons);
    glDisable(GL_POINT_SMOOTH);
    glDisable(GL_LINE_STIPPLE);


    glDisableClientState(GL_VERTEX_ARRAY);
//    print_matrix(obj.matrix);

}
//void Widget::print_matrix_new(matrix_t mat) {
//    for (int i = 0; i < mat.rows; i++) {
//        for (int j = 0; j < mat.columns; j++) {
//            qDebug() << mat.matrix[i][j];
//        }
////        printf("\n");
//    }
//}
//qDebug() << "This will output to the spawned console!";
//qDebug() << str;

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
