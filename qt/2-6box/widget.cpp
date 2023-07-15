#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->si=new signin;
    this->su=new signup;
    connect(this->si,&signin::to_home,this,&Widget::show);
    connect(this->su,&signup::to_home,this,&Widget::show);
    connect(this->su,&signup::to_in,this->si,&signin::retin);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buin_clicked()
{
    this->close();
    si->show();
}

void Widget::on_buup_clicked()
{
    this->close();
    su->show();
}

void Widget::on_bue_clicked()
{
    exit(0);
}
