#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->color_line_2, SIGNAL(clicked()), this, SLOT(on_color_line_2_clicked()));
    connect(ui->equal, SIGNAL(clicked()), this, SLOT(on_equal_clicked()));
//    connect(ui->combobox, SIGNAL(isChecked()), this, SLOT(on_comboBox_activated()));
    ui->x_size->setText("1");
    ui->y_size->setText("1");
    ui->z_size->setText("1");
    ui->x_move->setText("0");
    ui->y_move->setText("0");
    ui->z_move->setText("0");
    ui->x_turn->setText("0");
    ui->y_turn->setText("0");
    ui->z_turn->setText("0");
    ui->R1->setText("0");
    ui->G1->setText("0");
    ui->B1->setText("0");
    ui->R1_2->setText("1");
    ui->G1_2->setText("0");
    ui->B1_2->setText("0.5");
    ui->R1_3->setText("0");
    ui->G1_3->setText("0");
    ui->B1_3->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_plus_plus_clicked()
//{
//    ui->widget->filler(1, 0);
//}


void MainWindow::on_equal_clicked()
{
    double x = ui->x_size->text().toDouble();
    double y = ui->y_size->text().toDouble();
    double z = ui->z_size->text().toDouble();

    ui->widget->shift(1, x, y, z);
    create_screen();
}


void MainWindow::on_plus_plus_clicked()
{
    ui->widget->shift(1, 1.1, 1.1, 1.1);
    create_screen();
}


void MainWindow::on_minus_minus_clicked()
{
    ui->widget->shift(1, 0.9, 0.9, 0.9);
    create_screen();
}


void MainWindow::on_move_go_clicked()
{
    double x = ui->x_move->text().toDouble();
    double y = ui->y_move->text().toDouble();
    double z = ui->z_move->text().toDouble();

    ui->widget->shift(2, x, y, z);
    create_screen();
}




void MainWindow::on_rotate_clicked()
{
    double x = ui->x_turn->text().toDouble();
    double y = ui->y_turn->text().toDouble();
    double z = ui->z_turn->text().toDouble();

    ui->widget->shift(3, x, y, z);
    create_screen();
}


void MainWindow::on_restart_clicked()
{
    //ОТКЛЮЧИЛ ФУНКЦИЮ НИЖЕ ПОТОМУ ЧТО НУЖНО ТУДА ПЕРЕДАТЬ СТРОКУ
//    ui->widget->filler();
//    double x = ui->x_turn->text().toDouble();
//    double y = ui->y_turn->text().toDouble();
//    double z = ui->z_turn->text().toDouble();

//    ui->widget->shift(3, x, y, z);
//    x = ui->x_move->text().toDouble();
//    y = ui->y_move->text().toDouble();
//    z = ui->z_move->text().toDouble();

//    ui->widget->shift(2, x, y, z);

//    x = ui->x_size->text().toDouble();
//    y = ui->y_size->text().toDouble();
//    z = ui->z_size->text().toDouble();

//    ui->widget->shift(1, x, y, z);
    ui->widget->update();
    create_screen();
}


void MainWindow::on_comboBox_activated(int index)
{
    if (index == 0) {
        ui->widget->r1 = 255;
        ui->widget->g1 = 0;
        ui->widget->b1 = 0;
    } else if (index == 1) {
        ui->widget->r1 = 0;
        ui->widget->g1 = 255;
        ui->widget->b1 = 0;
    } else if (index == 2) {
        ui->widget->r1 = 0;
        ui->widget->g1 = 0;
        ui->widget->b1 = 255;
    } else if (index == 3) {
        ui->widget->r1 = 0;
        ui->widget->g1 = 0;
        ui->widget->b1 = 0;
    } else if (index == 4) {
        ui->widget->r1 = 255;
        ui->widget->g1 = 255;
        ui->widget->b1 = 255;
    } else {
        ui->widget->r1 = 0;
        ui->widget->g1 = 0;
        ui->widget->b1 = 0;
    }
    ui->widget->update();
}


void MainWindow::on_color_fon_clicked()
{
    ui->widget->r1 = ui->R1->text().toDouble();
    ui->widget->g1 = ui->G1->text().toDouble();
    ui->widget->b1 = ui->B1->text().toDouble();
    ui->widget->update();
    create_screen();
}


void MainWindow::on_color_line_clicked()
{
    ui->widget->r = ui->R1_2->text().toDouble();
    ui->widget->g = ui->G1_2->text().toDouble();
    ui->widget->b = ui->B1_2->text().toDouble();
    ui->widget->update();
    create_screen();
}


void MainWindow::on_width_plus_clicked()
{
    ui->widget->width += 0.5;
    ui->widget->update();
    create_screen();
}


void MainWindow::on_width_minus_clicked()
{
    ui->widget->width -= 0.5;
    ui->widget->update();
    create_screen();
}


void MainWindow::on_radioButton_2_toggled()
{
    ui->widget->line_type = 1;
    ui->widget->update();
}


void MainWindow::on_radioButton_toggled()
{
    ui->widget->line_type = 0;
    ui->widget->update();
}


void MainWindow::on_color_line_2_clicked()
{
    ui->widget->r2 = ui->R1_3->text().toDouble();
    ui->widget->g2 = ui->G1_3->text().toDouble();
    ui->widget->b2 = ui->B1_3->text().toDouble();
    ui->widget->point_size = ui->point_size2->text().toDouble();
    ui->widget->update();
    create_screen();
}


void MainWindow::on_radioButton_3_toggled()
{
    ui->widget->color_point = 1;
//    ui->widget->update();
}


void MainWindow::on_radioButton_4_toggled()
{
    ui->widget->color_point = 2;
//    ui->widget->update();
}


void MainWindow::on_radioButton_5_toggled()
{
    ui->widget->color_point = 3;
//    ui->widget->update();
}




void MainWindow::on_pushButton_open_clicked()
{
    //ПЕРЕД СОРКОЙ ПОМЕНЯТЬ НА /USERS/
//       QString path_to_file = QFileDialog::getOpenFileName(NULL, "Open", "/Users/corkiudy/C8_3DViewer_v1.0-0/src/gryffind_dev/obj", "*.obj");
    QString path_to_file = QFileDialog::getOpenFileName(NULL, "Open", "/Users/gryffind/C8_3DViewer_v1.0-1/src/gryffind_dev/obj/", "*.obj");
    char* path_to_file_str = new char[path_to_file.length()];
    QByteArray barr = path_to_file.toLatin1();
    strlcpy(path_to_file_str, barr, path_to_file.length() + 1);
    ui->widget->filler(path_to_file_str);

    char* file_name_str = strrchr(path_to_file_str, '/');

    change_information_about_obj(file_name_str);

    qDebug() << path_to_file_str;
    delete[] path_to_file_str;
    path_to_file_str = NULL;
    update();
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta() / 8;

    if (numDegrees.ry() == -15) {
//        отдалять
        ui->widget->shift(1, 1.1, 1.1, 1.1);
                qDebug() << 1;
    } else if (numDegrees.ry() == 15) {
//        приближать
        ui->widget->shift(1, 0.9, 0.9, 0.9);
        qDebug() << 0;
    }
    event->accept();
    create_screen();
}

void MainWindow::change_information_about_obj(char* file_name_str){
    QString file_name_q_str;
    file_name_q_str = file_name_str;
    qDebug() << file_name_q_str;

    int vertex = ui->widget->obj.count_of_vertex;
    int polygons = ui->widget->obj.count_of_polygons;
    QString str_vertex =  QString::number(vertex, 'g', 15);
    QString str_polygons =  QString::number(polygons, 'g', 15);
    ui->label_name->setText(file_name_q_str + "\nКоличество вершин: " + str_vertex + "\nКоличество полигонов: " + str_polygons);
}






void MainWindow::create_screen()
{
    if (flag == 1) {
        mas_image.push_back(ui->widget->grab().toImage());
    }
}

void MainWindow::on_jpeg_pressed()
{
    QString file = QFileDialog::getSaveFileName(this, "Save as...", "name", "BMP (*.bmp);; JPEG (*.jpeg)");
        ui->widget->grab().save(file);
}


void MainWindow::on_start_screen_pressed()
{
    flag = 1;
}


void MainWindow::on_stop_screen_pressed()
{
    flag = 0;
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save screenshot"), "", tr("GIF screenshot (*.gif);;GIF screenshot (*.gif)"));
        QGifImage gif(QSize(5000, 5000));
        QVector<QRgb> ctable;
        ctable << qRgb(255, 255, 255)
               << qRgb(0, 0, 0)
               << qRgb(255, 0, 0)
               << qRgb(0, 255, 0)
               << qRgb(0, 0, 255)
               << qRgb(255, 255, 0)
               << qRgb(0, 255, 255)
               << qRgb(255, 0, 255);

        gif.setGlobalColorTable(ctable, Qt::black);
        gif.setDefaultTransparentColor(Qt::black);
        gif.setDefaultDelay(100);

        for (QVector<QImage>::Iterator img = mas_image.begin(); img != mas_image.end(); ++img) {
            gif.addFrame(*img);
        }
        gif.save(fileName);

}

