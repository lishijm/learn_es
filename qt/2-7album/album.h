#ifndef ALBUM_H
#define ALBUM_H

#include <QWidget>
#include <QDebug>
#include <QPixmap>
#include <QPalette>
#include <QTimer>
#include <QLabel>
#include <QDateTime>


namespace Ui {
class album;
}

class album : public QWidget
{
    Q_OBJECT

public:
    explicit album(QWidget *parent = nullptr);
    ~album();

signals:
    void to_home();

private slots:
    void on_rebut_clicked();

    void on_downbut_clicked();

    void on_upbut_clicked();

    void update_time();

private:
    Ui::album *ui;
    int fileid=0;
    QTimer *qtr;
    QLabel *qlb;
};

#endif // ALBUM_H
