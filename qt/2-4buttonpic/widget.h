#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMovie>
#include <QDebug>
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
    void on_playbuton_clicked();

private:
    Ui::Widget *ui;
    int play_flag=1;
    QMovie *mv;
};

#endif // WIDGET_H
