#ifndef NMUSERSEL_H
#define NMUSERSEL_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class nmusersel;
}

class nmusersel : public QWidget
{
    Q_OBJECT

public:
    explicit nmusersel(QWidget *parent = nullptr);
    ~nmusersel();

public slots:
    void resg(QTcpSocket *);

signals:
    void to_sin();

    void to_sup();

    void sgsksin(QTcpSocket *);

    void sgsksup(QTcpSocket *);

private slots:
    void on_nmselinbtn_clicked();

    void on_nmselupbtn_clicked();

private:
    Ui::nmusersel *ui;

    QTcpSocket *netsokt;
};

#endif // NMUSERSEL_H
