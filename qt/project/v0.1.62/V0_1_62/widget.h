#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include "setnet.h"
#include "nmuserin.h"
#include "signup.h"
#include "aduserin.h"
#include "aduserf.h"
#include "nmusersel.h"
#include "aulook.h"
#include "ausearch.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    QTcpSocket *sokt;

signals:
    void sgsksn(QTcpSocket *);

    void sgskausin(QTcpSocket *);

    void sgsknusel(QTcpSocket *);

private slots:

    void on_nsbtn_clicked();

    void on_nubtn_clicked();

    void on_aubtn_clicked();

private:
    Ui::Widget *ui;
    setnet *sn;
    nmuserin *nusin;
    signup *sup;
    aduserin *ausin;
    aduserf *ausf;
    nmusersel *nusel;
    aulook *aulk;
    ausearch *ausc;

};

#endif // WIDGET_H
