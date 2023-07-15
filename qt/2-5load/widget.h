#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProgressBar>

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
    void on_startbuton_clicked();

private:
    Ui::Widget *ui;
    QTimerEvent *ev;
};

#endif // WIDGET_H
