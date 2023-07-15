#include "signup.h"
#include "ui_signup.h"
#include<QMessageBox>

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    netsokt=nullptr;
}

signup::~signup()
{
    delete ui;
}

void signup::on_upclbtn_clicked()
{
    QString inf="0\n";
    netsokt->write(inf.toStdString().c_str());
    emit to_home();
    this->close();
}

void signup::on_upupbtn_clicked()
{
    QString inf="1\n";
    inf.append(this->ui->upnameline->text());
    inf.append("\n");
    QString passwd=this->ui->uppwdline->text();
    QString passwdr=this->ui->uprpwdline->text();
    if(passwd==passwdr){
        inf.append(passwd);
        netsokt->write(inf.toStdString().c_str());
    }
    else{
        QMessageBox::warning(this,"password","password inconsistent");
    }
}

void signup::resg(QTcpSocket *tmpsokt){
    netsokt=tmpsokt;
    connect(netsokt,&QTcpSocket::readyRead,this,&signup::soktre);
    netsokt->write(SIGNIN);
}

void signup::soktre(){
    int flag=0;
    QString buf=netsokt->readAll();
    sscanf(buf.toStdString().data(),"#%d#",&flag);
    qDebug()<<flag;
    if(flag==1){
        disconnect(netsokt,&QTcpSocket::readyRead,this,&signup::soktre);
        QMessageBox::warning(this,"sign up","sign up ok");
        emit to_home();
        this->close();
    }
    else{
        disconnect(netsokt,&QTcpSocket::readyRead,this,&signup::soktre);
        QMessageBox::warning(this,"sign up","sign up error");
        emit to_home();
        this->close();
    }
}
