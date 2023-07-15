#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "signin.h"
#include "signup.h"
#include "album.h"

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
    void on_bue_clicked();

    void on_buin_clicked();

    void on_buup_clicked();

private:
    Ui::Widget *ui;
    signin *si;
    signup *su;
    album *am;
    sql_opr sq1;
};

#endif // WIDGET_H
