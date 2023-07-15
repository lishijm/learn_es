#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QDateTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void update_time();

private:
    Ui::Widget *ui;
    QTimer *timer_1;
    QLabel *lab_1;
};

#endif // WIDGET_H
