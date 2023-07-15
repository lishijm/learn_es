#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void mousePressEvent(QMouseEvent *);

    void mouseMoveEvent(QMouseEvent *);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
