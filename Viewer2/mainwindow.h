#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget.h"


extern "C" {
#include "../src/gryffind_dev/parsing.h"
#include "../src/gryffind_dev/matrix/s21_matrix.h"
#include "../src/gryffind_dev/afinn_translation.h"
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_plus_plus_clicked();

    void on_equal_clicked();

    void on_plus_plus_clicked();

    void on_minus_minus_clicked();

    void on_move_go_clicked();

    void on_rotate_clicked();

    void on_restart_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
