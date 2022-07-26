#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget.h"
#include <QFileDialog>
#include <QVector>
#include <QImage>
#include "../QtGifImage-master/src/gifimage/qgifimage.h"
#include <QPainter>
#include <QPixmap>
#include <QSize>
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
    int flag;
    QVector<QImage> mas_image;
    void on_comboBox_activated(int index);

private slots:
//    void on_plus_plus_clicked();

    void on_equal_clicked();

    void on_plus_plus_clicked();

    void on_minus_minus_clicked();

    void on_move_go_clicked();

    void on_rotate_clicked();

    void on_restart_clicked();



    void on_color_fon_clicked();

    void on_color_line_clicked();

    void on_width_plus_clicked();

    void on_width_minus_clicked();

//    void on_radioButton_2_toggled();

    void on_radioButton_toggled();

    void on_color_line_2_clicked();

    void on_radioButton_3_toggled();

    void on_radioButton_4_toggled();

    void on_radioButton_5_toggled();

    void on_pushButton_open_clicked();
        void wheelEvent(QWheelEvent *event) override;
    void change_information_about_obj(char* file_name_str);

    void create_screen();
    void on_radioButton_2_toggled();
    void on_jpeg_pressed();

    void on_start_screen_pressed();

    void on_stop_screen_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
