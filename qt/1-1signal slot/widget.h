#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void update_text();
    void clear_text();
private:
    Ui::Widget *ui;
    QPushButton *button1;
    QPushButton *button2;
    QTextEdit  *te;
};

#endif // WIDGET_H
