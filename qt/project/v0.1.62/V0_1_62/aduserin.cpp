#include "aduserin.h"
#include "ui_aduserin.h"
#include <QMessageBox>
#include <QTime>

aduserin::aduserin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aduserin)
{
    ui->setupUi(this);
    netsokt=nullptr; 

}

aduserin::~aduserin()
{
    delete ui;
}

void aduserin::on_adclbtn_clicked()
{
#if 0
    QString inf="0\n";
    netsokt->write(inf.toStdString().c_str());
#endif
    disconnect(netsokt,&QTcpSocket::readyRead,this,&aduserin::soktre);
    emit to_home();
    this->close();
}

void aduserin::on_adsinbtn_clicked()
{
    netsokt->write(ALOGIN);
    this->Sleep(25);
    QString inf="1\n";
    inf.append(this->ui->adnameline->text());
    inf.append('\n');
    inf.append(this->ui->adpwdline->text());

    netsokt->write(inf.toStdString().c_str());
}
void aduserin::resg(QTcpSocket *tmpsokt){
    netsokt=tmpsokt;
    connect(netsokt,&QTcpSocket::readyRead,this,&aduserin::soktre);
}

void aduserin::soktre(){
    int flag=2;
    QString buf=netsokt->readAll();
    sscanf(buf.toStdString().data(),"#%d#",&flag);
    if(1==flag){
        QMessageBox::warning(this,"sign in","sign in ok");
        emit sgsktof(netsokt);
        emit to_function();
        disconnect(netsokt,&QTcpSocket::readyRead,this,&aduserin::soktre);
        this->close();
    }
    else if(0==flag){
        QMessageBox::warning(this,"sign in","sign in error");
    }
}

void aduserin::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
