#ifndef AULOOK_H
#define AULOOK_H

#include <QWidget>
#include <QTcpSocket>
#define AD_VIEW "a_view"

namespace Ui {
class aulook;
}

class aulook : public QWidget
{
    Q_OBJECT

public:
    explicit aulook(QWidget *parent = nullptr);
    ~aulook();

signals:
    void to_aultof();

public slots:
    void resg(QTcpSocket *);

    void soktre();

private slots:
    void on_lkrbtn_clicked();

private:
    Ui::aulook *ui;

    QTcpSocket *netsokt;

#if 1
    int readrow;

    int readcolumn;

    int tmp;
#endif
    bool flag;

    QString res;
};

#endif // AULOOK_H
