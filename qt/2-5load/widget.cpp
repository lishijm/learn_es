#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->ui->prg1->setRange(0,100);
    this->ui->prg1->setValue(0);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startbuton_clicked()
{
    for(int i=0;i<=100;i++){
        this->ui->prg1->setValue(i);
    }
}
