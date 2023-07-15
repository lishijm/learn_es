#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->lab_1=new QLabel(this);
    this->timer_1=new QTimer(this);

    this->lab_1->setGeometry(100,50,200,80);

    connect(this->timer_1,SIGNAL(timeout()),this,SLOT(update_time()));

    this->timer_1->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::update_time()
{
    QString ti=QDateTime::currentDateTime().toString();

    this->lab_1->setText(ti);
}
