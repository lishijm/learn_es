#ifndef AUSEARCH_H
#define AUSEARCH_H

#include <QWidget>
#include <QTcpSocket>
#define SEARCH "search"
#include <QMessageBox>

namespace Ui {
class ausearch;
}

class ausearch : public QWidget
{
    Q_OBJECT

public:
    explicit ausearch(QWidget *parent = nullptr);
    ~ausearch();

    void Sleep(int);

signals:
    void to_asctof();

public slots:
    void resg(QTcpSocket *);

    void sokre();

private slots:
    void on_asclbtn_clicked();

    void on_asearbtn_clicked();

private:
    Ui::ausearch *ui;

    QTcpSocket *netsokt;

    bool flag;
    bool flagtime;
    int readcolumn;
    int readrow;
    int tmp;

    int resflag;

    QString res;
};

#endif // AUSEARCH_H
