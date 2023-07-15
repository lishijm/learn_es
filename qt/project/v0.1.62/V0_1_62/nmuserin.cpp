#include "nmuserin.h"
#include "ui_nmuserin.h"
#include <QMessageBox>
#include <QDebug>
#include <QTime>

nmuserin::nmuserin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nmuserin)
{
    ui->setupUi(this);
    netsokt=nullptr;
    this->fp=nullptr;
    this->pic_src.clear();
    this->flag=0;
    this->sht=new showthread;
    this->svt=new savethread;
#if 1
    connect(this->sht,&showthread::send_img,this,&nmuserin::recv_img);
    connect(this->sht,&showthread::send_mat,this->svt,&savethread::recv_mat,Qt::DirectConnection);

#endif
}

nmuserin::~nmuserin()
{
    delete ui;
}

void nmuserin::on_nminbtn_clicked()
{
    netsokt->write(NLOGIN);
    this->Sleep(25);
#if 0
    this->svt->start();
    this->svt->quit();
    this->svt->wait();
#endif
    QString inf="1\n";
    inf.append(this->ui->nminnameline->text());
    inf.append("\n");
    inf.append(this->ui->nminpasswdline->text());

    netsokt->write(inf.toStdString().c_str());

}
#if 0
void nmuserin::on_insubtn_clicked()
{
    disconnect(netsokt,&QTcpSocket::readyRead,this,&nmuserin::soktre);
    this->sht->set_flag(1);
    this->Sleep(25);
    this->sht->quit();
    this->sht->wait();
    QString inf="0\n";
    netsokt->write(inf.toStdString().c_str());
    emit to_signup();
    emit sgsk(netsokt);
    this->close();
}
#endif

void nmuserin::on_nminclbtn_clicked()
{
    this->sht->set_flag(1);
    this->Sleep(25);
    this->sht->quit();
    this->sht->wait();
#if 0
    netsokt->write(NLOGIN);
    this->Sleep(25);
    QString inf="0\n";
    netsokt->write(inf.toStdString().c_str());
#endif
    disconnect(netsokt,&QTcpSocket::readyRead,this,&nmuserin::soktre);
    emit to_home();
    this->close();
}

void nmuserin::resg(QTcpSocket *tmpsokt){
#if 0
    this->sht->start();
    this->sht->set_flag(0);
#endif
    netsokt=tmpsokt;
    connect(netsokt,&QTcpSocket::readyRead,this,&nmuserin::soktre);
}

#if 0
void nmuserin::on_tkptbtn_clicked()
{
    this->svt->start();
    this->svt->quit();
    this->svt->wait();
}

void nmuserin::on_clcabtn_clicked()
{
    this->sht->set_flag(1);
    this->Sleep(25);
    this->sht->quit();
    this->sht->wait();
}
#endif

void nmuserin::recv_img(const QImage simg){
    this->img=simg;
    if(img.isNull()){
        return ;
    }
    if(this->flag==0){
        this->svt->set_wh(img.width(),img.height());
        this->flag=1;
    }
    this->ui->caml->setPixmap(QPixmap::fromImage(this->img).scaled(this->ui->caml->size()));
    this->update();
}

void nmuserin::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void nmuserin::soktre(){
    int flag=1;
    QString buf=netsokt->readAll();
    sscanf(buf.toStdString().data(),"#%d#",&flag);
    if(flag==0){
        QMessageBox::warning(this,"sign in","sign in error");
    }
    else{
#if 1
        char sizehead[100]={0};
        QFileInfo info("./img.jpg");
        sprintf(sizehead,"#%d#",info.size());
        this->Sleep(25);
        netsokt->write(sizehead);
        qDebug()<<sizehead;

        this->fp=fopen("./img.jpg","rb");
        char buf[1024];
        uint ret=0;
        for (;;) {
            memset(buf,0,sizeof (buf));
            ret=fread(buf,sizeof(char),sizeof (buf),fp);
            //qDebug()<<ret;
            if(ret==0){
                break;
            }
            netsokt->write(buf, 1024);
            this->Sleep(50);
        }
        fclose(fp);
#endif
        QMessageBox::warning(this,"sign in","sign in ok");
    }
}
