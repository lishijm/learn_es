#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <math.h>
#include <QMessageBox>
#include <iostream>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_cul_clicked();

    void on_cle_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
