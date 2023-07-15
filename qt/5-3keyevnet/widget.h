#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void keypressevent(QKeyEvent *);

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
