#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->sn=new setnet;
    this->nusin=new nmuserin;
    this->sup=new signup;
    this->ausin=new aduserin;
    this->ausf=new aduserf;
    this->sokt=new QTcpSocket;
    this->nusel=new nmusersel;
    this->aulk=new aulook;
    this->ausc=new ausearch;

    connect(this->sn,&setnet::to_home,this,&Widget::show);
    connect(this->nusin,&nmuserin::to_home,this,&Widget::show);
    connect(this->sup,&signup::to_home,this,&Widget::show);
    connect(this->nusel,&nmusersel::to_sin,this->nusin,&nmuserin::show);
    connect(this->nusel,&nmusersel::to_sup,this->sup,&signup::show);
    connect(this->ausin,&aduserin::to_home,this,&Widget::show);
    connect(this->ausin,&aduserin::to_function,this->ausf,&aduserf::show);
    connect(this->ausf,&aduserf::to_look,this->aulk,&aulook::show);
    connect(this->ausf,&aduserf::to_search,this->ausc,&ausearch::show);
    connect(this->ausf,&aduserf::to_home,this,&Widget::show);

    connect(this->aulk,&aulook::to_aultof,this->ausf,&aduserf::show);
    connect(this->ausc,&ausearch::to_asctof,this->ausf,&aduserf::show);

    connect(this,&Widget::sgsksn,this->sn,&setnet::resg);
    connect(this,&Widget::sgskausin,this->ausin,&aduserin::resg);
    connect(this,&Widget::sgsknusel,this->nusel,&nmusersel::resg);
    connect(this->ausin,&aduserin::sgsktof,this->ausf,&aduserf::resg);
    connect(this->ausf,&aduserf::sgskalk,this->aulk,&aulook::resg);
    connect(this->ausf,&aduserf::sgskasc,this->ausc,&ausearch::resg);
    connect(this->nusel,&nmusersel::sgsksin,this->nusin,&nmuserin::resg);
    connect(this->nusel,&nmusersel::sgsksup,this->sup,&signup::resg);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_nsbtn_clicked()
{
    emit sgsksn(sokt);
    this->close();
    sn->show();
}

void Widget::on_nubtn_clicked()
{
    emit sgsknusel(sokt);
    this->close();
    nusel->show();
}

void Widget::on_aubtn_clicked()
{
    emit sgskausin(sokt);
    this->close();
    ausin->show();
}
