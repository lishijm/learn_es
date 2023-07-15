#include "aulook.h"
#include "ui_aulook.h"

aulook::aulook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aulook)
{
    ui->setupUi(this);
}

aulook::~aulook()
{
    delete ui;
}

void aulook::resg(QTcpSocket *tmpsokt)
{
    this->ui->lkres->clear();
    netsokt=tmpsokt;
    netsokt->write(AD_VIEW);
    flag=false;
    readcolumn=0;
    readrow=0;
    tmp=0;
    connect(netsokt,&QTcpSocket::readyRead,this,&aulook::soktre);
}

void aulook::on_lkrbtn_clicked()
{
    emit to_aultof();
    disconnect(netsokt,&QTcpSocket::readyRead,this,&aulook::soktre);
    this->close();
}

void aulook::soktre(){
    if(flag==false){
        QString head=netsokt->read(10);
        int row=0,column=0;
        sscanf(head.toStdString().c_str(),"#%d#%d#",&row,&column);
        qDebug()<<row<<"x"<<column;
        readcolumn=column;
        readrow=row;
        tmp=column;
        flag=true;
    }
    else if(flag==true){
        res.append(netsokt->readAll());
        res.append("  ");
        readcolumn--;
        if(readcolumn==0){
            this->ui->lkres->addItem(res);
            res.clear();
            readcolumn=tmp;
        }
    }
}
