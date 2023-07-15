#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap("./wallpaper.png").scaled(this->size())));
    this->setPalette(pal);
    //this->ui->in1->setStyleSheet("border-image:url(./wallpaper.png)");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_in1_clicked()
{
    QPixmap pm;
    pm.load("./wallpaper.png");
#if 0
    this->ui->label->setPixmap(pm.scaled(this->ui->label->size()));
#endif

#if 1
    this->ui->label->setScaledContents(true);
    this->ui->label->setPixmap(pm);
#endif
}

void Widget::on_in2_clicked()
{
    this->ui->label->clear();
}
