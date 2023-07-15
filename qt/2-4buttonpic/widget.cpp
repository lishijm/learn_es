#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->mv=new QMovie(this);
    this->mv->setFileName(":/1681193670803.gif");
    this->ui->gifshow->setMovie(mv);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_playbuton_clicked()
{

    //this->mv->start();
#if 1
    if(play_flag==1){
        this->ui->playbuton->setText("pause");
        this->mv->start();
    }
    else if(play_flag==-1){
        this->ui->playbuton->setText("play");
        this->mv->stop();
    }
    play_flag=play_flag*(-1);
    qDebug()<<play_flag;

#endif
}
