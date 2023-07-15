#ifndef SETNET_H
#define SETNET_H

#include <QWidget>
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

namespace Ui {
class setnet;
}

class setnet : public QWidget
{
    Q_OBJECT

public:
    explicit setnet(QWidget *parent = nullptr);
    ~setnet();

public slots:
    void resg(QTcpSocket *);

signals:
    void to_home();

private slots:
    void on_nsclbtn_clicked();

    void on_nsconbtn_clicked();

private:
    Ui::setnet *ui;

    QTcpSocket *netsokt;
};

#endif // SETNET_H
