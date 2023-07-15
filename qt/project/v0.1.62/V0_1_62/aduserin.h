#ifndef ADUSERIN_H
#define ADUSERIN_H

#include <QWidget>
#include <QTcpSocket>

using namespace std;

#define ALOGIN "a_login"

namespace Ui {
class aduserin;
}

class aduserin : public QWidget
{
    Q_OBJECT

public:
    explicit aduserin(QWidget *parent = nullptr);
    ~aduserin();

    void sleep(int);

    void Sleep(int);

public slots:
    void resg(QTcpSocket *);

    void soktre();

signals:
    void to_home();

    void to_function();

    void sgsktof(QTcpSocket *);

private slots:
    void on_adclbtn_clicked();

    void on_adsinbtn_clicked();

private:
    Ui::aduserin *ui;

    QTcpSocket *netsokt;
};

#endif // ADUSERIN_H
