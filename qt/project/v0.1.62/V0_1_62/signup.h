#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QTcpSocket>

#define SIGNIN "signin"

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

public slots:
    void resg(QTcpSocket *);

    void soktre();

signals:
    void to_home();

private slots:
    void on_upclbtn_clicked();

    void on_upupbtn_clicked();

private:
    Ui::signup *ui;

    QTcpSocket *netsokt;
};

#endif // SIGNUP_H
