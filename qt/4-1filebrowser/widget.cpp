#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    dirctp=new QDir;
    this->ui->path_edit->setText("C:\\Users\\JUEMING SHI\\Documents");
    dir_show();
}

Widget::~Widget()
{
    delete ui;
    delete dirctp;
}

void Widget::dir_show(){
    this->ui->listWidget->clear();
    QString path=this->ui->path_edit->text();
    this->dirctp->setPath(path);
    QStringList namelist;
    namelist<<"*";

    QFileInfoList filelist=this->dirctp->entryInfoList(namelist,QDir::AllEntries,QDir::DirsFirst);
    for(int i=0;i<filelist.size();i++){
        QListWidgetItem *item=new QListWidgetItem;
        item->setText(filelist.at(i).fileName());
        if(filelist.at(i).isDir()==true){

        }
        else{

        }
        this->ui->listWidget->addItem(item);
    }
}
#if 1
void Widget::on_ft_dir_clicked()
{
    bool res=this->dirctp->cdUp();
    if(res==true){
        path=this->dirctp->absolutePath();
        this->ui->path_edit->setText(path);
        this->dir_show();
    }
}

void Widget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug()<<"dc";
    QString name=item->text();
    bool res=this->dirctp->cd(name);
    if(res==true){
        QString path=this->dirctp->absolutePath();
        this->ui->path_edit->setText(path);
        this->dir_show();
    }
    else{

    }
}
#endif
