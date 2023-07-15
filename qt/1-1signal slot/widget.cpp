#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->button1=new QPushButton("显示",this);
    this->button2=new QPushButton("清除",this);
    this->te=new QTextEdit(this);

    this->button1->move(10,10);
    this->button2->move(50,10);
    this->button1->resize(40,40);
    this->button2->resize(40,40);

    this->te->setGeometry(50,60,70,80);


    connect(this->button1,SIGNAL(clicked()),this,SLOT(update_text()));

    connect(this->button2,&QPushButton::clicked,this,&Widget::clear_text);
        //连接信号和槽第三方式
    //connect(this->button1,&QPushButton::clicked,[=](){this->te->setText("11111");});
}

Widget::~Widget()
{
    delete ui;
}

void Widget::update_text(){
    this->te->setText("info");
}

void Widget::clear_text(){
    this->te->clear();
}
