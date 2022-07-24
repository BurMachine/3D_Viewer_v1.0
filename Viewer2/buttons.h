#ifndef BUTTONS_H
#define BUTTONS_H

#include <QDialog>

namespace Ui {
class Buttons;
}

class Buttons : public QDialog
{
    Q_OBJECT

public:
    explicit Buttons(QWidget *parent = nullptr);
    ~Buttons();

private slots:
    void on_PLUS_clicked();

private:
    Ui::Buttons *ui;
};

#endif // BUTTONS_H
