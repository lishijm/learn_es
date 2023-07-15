#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include <QMessageBox>
#include "sqlite.h"

namespace Ui {
class signin;
}

class signin : public QWidget
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();

signals:
    void to_home();
    void to_album();

private slots:
    void on_returin_clicked();

    void on_busin_clicked();

private:
    Ui::signin *ui;
    QString name;
    QString password;
    sql_opr sq1;
};

#endif // SIGNIN_H
