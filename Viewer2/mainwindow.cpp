#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->equal, SIGNAL(clicked()), this, SLOT(on_equal_clicked()));
    ui->x_size->setText("1");
    ui->y_size->setText("1");
    ui->z_size->setText("1");
    ui->x_move->setText("0");
    ui->y_move->setText("0");
    ui->z_move->setText("0");
    ui->x_turn->setText("0");
    ui->y_turn->setText("0");
    ui->z_turn->setText("0");
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

}


void MainWindow::on_plus_plus_clicked()
{
    ui->widget->shift(1, 1.1, 1.1, 1.1);
}


void MainWindow::on_minus_minus_clicked()
{
    ui->widget->shift(1, 0.9, 0.9, 0.9);
}


void MainWindow::on_move_go_clicked()
{
    double x = ui->x_move->text().toDouble();
    double y = ui->y_move->text().toDouble();
    double z = ui->z_move->text().toDouble();

    ui->widget->shift(2, x, y, z);
}




void MainWindow::on_rotate_clicked()
{
    double x = ui->x_turn->text().toDouble();
    double y = ui->y_turn->text().toDouble();
    double z = ui->z_turn->text().toDouble();

    ui->widget->shift(3, x, y, z);
}


void MainWindow::on_restart_clicked()
{
    ui->widget->filler();
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
}

