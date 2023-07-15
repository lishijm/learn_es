#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keypressevent(QKeyEvent *event){
    if(event->key()=='a'){
        qDebug()<<"a";
    }
}

void Widget::on_lineEdit_textEdited(const QString &arg1)
{

}
