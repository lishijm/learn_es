#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void timerEvent(QTimerEvent* ev);
    ~Widget();

private slots:
    void on_stbut_clicked();

private:
    Ui::Widget *ui;
    int timer;
    int time;
};

#endif // WIDGET_H
