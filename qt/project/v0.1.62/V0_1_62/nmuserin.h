#ifndef NMUSERIN_H
#define NMUSERIN_H

#include <QWidget>
#include <QTcpSocket>
#include "savethread.h"
#include "showthread.h"
#include <stdio.h>
#include <QByteArray>
#include <QFileInfo>

#define NLOGIN "n_login"

namespace Ui {
class nmuserin;
}

class nmuserin : public QWidget
{
    Q_OBJECT

public:
    explicit nmuserin(QWidget *parent = nullptr);
    ~nmuserin();

    void Sleep(int);

public slots:
    void resg(QTcpSocket *);

    void recv_img(const QImage);

    void soktre();

signals:
    void to_home();

private slots:
    void on_nminbtn_clicked();

    void on_nminclbtn_clicked();

#if 0
    void on_tkptbtn_clicked();

    void on_clcabtn_clicked();
#endif
private:
    Ui::nmuserin *ui;
    QTcpSocket *netsokt;
    savethread *svt;    
    showthread *sht;
    QImage img;
    int flag;   
    FILE *fp;
    QByteArray pic_src;

};

#endif // NMUSERIN_H
