#include "ausearch.h"
#include "ui_ausearch.h"
#include <QTime>

ausearch::ausearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ausearch)
{
    ui->setupUi(this);
}

ausearch::~ausearch()
{
    delete ui;
}

void ausearch::resg(QTcpSocket *tmpskot)
{
    netsokt=tmpskot;
    connect(netsokt,&QTcpSocket::readyRead,this,&ausearch::sokre);
}

void ausearch::on_asclbtn_clicked()
{
    disconnect(netsokt,&QTcpSocket::readyRead,this,&ausearch::sokre);
    emit to_asctof();
    this->close();
}

void ausearch::on_asearbtn_clicked()
{
    this->ui->scres->clear();
    netsokt->write(SEARCH);
    this->Sleep(25);
    flagtime=false;
    flag=false;
    readcolumn=0;
    readrow=0;
    tmp=0;
    resflag=2;
    netsokt->write(this->ui->nameline->text().toStdString().c_str());
}

void ausearch::sokre(){
    if(flagtime==false){
        QString res=netsokt->readAll();
        sscanf(res.toStdString().data(),"#%d#",&resflag);
        qDebug()<<resflag;
        if(1==resflag){
            flagtime=true;
        }
        else if(0==resflag){
            QMessageBox::warning(this,"search","not found");
            disconnect(netsokt,&QTcpSocket::readyRead,this,&ausearch::sokre);
            emit to_asctof();
            this->close();
        }
    }
    else if(flagtime==true){
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
                this->ui->scres->addItem(res);
                res.clear();
                readcolumn=tmp;
            }
        }
    }
}

void ausearch::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
