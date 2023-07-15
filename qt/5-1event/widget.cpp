#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this->ui->lc,&lableclic::click,this,&Widget::paint);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paint(){
    qDebug()<<"x";
}
