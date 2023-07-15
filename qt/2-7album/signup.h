#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QMessageBox>
#include "sqlite.h"

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

signals:
    void to_home();
    void to_in(const QString,const QString);
private slots:
    void on_returnup_clicked();

    void on_buup_clicked();

private:
    Ui::signup *ui;
    sql_opr sq1;
};

#endif // SIGNUP_H
