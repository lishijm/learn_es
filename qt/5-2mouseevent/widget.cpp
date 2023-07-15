#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置光标追踪
    this->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *pressevent){
    if(pressevent->button()==Qt::LeftButton){
        qDebug()<<"left";
    }
    if(pressevent->button()==Qt::RightButton){
        qDebug()<<"right";
    }
    if(pressevent->button()==Qt::MidButton){
        qDebug()<<"mid";
    }
}

void Widget::mouseMoveEvent(QMouseEvent *movevent){
    qDebug()<<"x:"<<movevent->x();
    qDebug()<<"y:"<<movevent->y();
}
