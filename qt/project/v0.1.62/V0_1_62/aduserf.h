#ifndef ADUSERF_H
#define ADUSERF_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class aduserf;
}

class aduserf : public QWidget
{
    Q_OBJECT

public:
    explicit aduserf(QWidget *parent = nullptr);
    ~aduserf();

public slots:
    void resg(QTcpSocket *);

signals:
    void to_look();

    void to_search();

    void to_home();

    void sgskalk(QTcpSocket *);

    void sgskasc(QTcpSocket *);

private slots:
    void on_adflbtn_clicked();

    void on_adsbtn_clicked();

    void on_adexitbtn_clicked();

private:
    Ui::aduserf *ui;

    QTcpSocket *netsokt;
};

#endif // ADUSERF_H
