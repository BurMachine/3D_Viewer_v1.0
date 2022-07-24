#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->equal, SIGNAL(clicked()), this, SLOT(on_equal_clicked()));
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
    ui->widget->filler(1, x, y, z);
}

