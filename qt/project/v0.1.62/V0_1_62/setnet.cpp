#include "setnet.h"
#include "ui_setnet.h"

setnet::setnet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setnet)
{
    ui->setupUi(this);

    netsokt=nullptr;

}

setnet::~setnet()
{
    delete ui;
}

void setnet::on_nsclbtn_clicked()
{
    emit to_home();
    this->close();
}

void setnet::on_nsconbtn_clicked()
{
    QString qip=this->ui->ipline->text();
    quint16 qport=this->ui->portline->text().toInt();
    netsokt->connectToHost(QHostAddress(qip),qport);
    qDebug()<<netsokt->state();
}

void setnet::resg(QTcpSocket *tmpsokt){
    netsokt=tmpsokt;
    connect(netsokt,&QTcpSocket::connected, this, [=](){
        QMessageBox::warning(this,"netcon","connect ok");
        this->close();
        emit to_home();
    });
}
