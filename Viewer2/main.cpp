#include "widget.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
//ШТУКИ НЕОБХОДИМЫЕ ДЛЯ ДЕБАГИНГА
//qDebug() << "This will output to the spawned console!";
//qDebug() << str;


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


//double ver[] = {
//    1.000000, -1.000000, -1.000000,
//    1.000000, -1.000000, 1.000000,
//    -1.000000, -1.000000, 1.000000,
//    -1.000000, -1.000000, -1.000000,
//    1.000000, 1.000000, -0.999999,
//    0.999999, 1.000000, 1.000001,
//    -1.000000, 1.000000, 1.000000,
//    -1.000000, 1.000000, -1.000000
//    };
//unsigned int facets[] = {
//    1, 2, 2, 3, 3, 1,
//    7, 6, 6, 5, 5, 7,
//    4, 5, 5, 1, 1, 4,
//    5, 6, 6, 2, 2, 5,
//    2, 6, 6, 7, 7, 2,
//    0, 3, 3, 7, 7, 0,
//    0, 1, 1, 3, 3, 0,
//    4, 7, 7, 5, 5, 4,
//    0, 4, 4, 1, 1, 0,
//    1, 5, 5, 2, 2, 1,
//    3, 2, 2, 7, 7, 3,
//    4, 0, 0, 7, 7, 4
//};
