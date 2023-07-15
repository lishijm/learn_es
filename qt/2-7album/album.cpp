#include "album.h"
#include "ui_album.h"
#include <iostream>
#include <string>
#include <QFont>
using namespace std;

album::album(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::album)
{
    ui->setupUi(this);
    this->qlb=new QLabel(this);
    this->qtr=new QTimer(this);
    QFont ft;
    ft.setPointSize(26);
    qlb->setFont(ft);
    this->qlb->setGeometry(192,210,640,51);
    connect(this->qtr,SIGNAL(timeout()),this,SLOT(update_time()));
    this->qtr->start(1000);

}

album::~album()
{
    delete ui;
}

void album::on_rebut_clicked()
{
    this->close();
    emit to_home();
}

void album::on_downbut_clicked()
{
    fileid++;
    if(fileid>2){
       fileid=1;
    }
    QPixmap pm;
    string idname=to_string(fileid);
    string filename="./"+idname+".png";
    QString filenameq=QString::fromStdString(filename);
    pm.load(filenameq);
    this->ui->imgshow->setScaledContents(true);
    this->ui->imgshow->setPixmap(pm);
}

void album::on_upbut_clicked()
{
    fileid--;
    if(fileid<1){
       fileid=2;
    }
    QPixmap pm;
    string idname=to_string(fileid);
    string filename="./"+idname+".png";
    QString filenameq=QString::fromStdString(filename);
    pm.load(filenameq);
    this->ui->imgshow->setScaledContents(true);
    this->ui->imgshow->setPixmap(pm);
}

void album::update_time()
{
    QString ti=QDateTime::currentDateTime().toString();
    QString til=QDateTime::currentDateTime().toString("hh:mm:ss");
    this->ui->time1->setDigitCount(8);
    this->ui->time1->display(til);

    this->qlb->setText(ti);
}
