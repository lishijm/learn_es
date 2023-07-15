#include "widget.h"
#include "ui_widget.h"

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

void Widget::on_stbut_clicked()
{
    timer=startTimer(1000);
    time=this->ui->txt->text().toInt();
    if(time<0){
        QMessageBox::warning(this,"timer","time can't small than zero");
    }

}
void Widget::timerEvent(QTimerEvent* ev){//定时事件
    if(ev->timerId() == timer&&time>0){
        time--;
        this->ui->txt->setText(QString::number(time));

    }
    if(time==0){
        QMessageBox::warning(this,"timer","time has been over");
        killTimer(timer);
    }
    if(time<0){
        killTimer(timer);
    }
}
