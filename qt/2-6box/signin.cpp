#include "signin.h"
#include "ui_signin.h"
#include "widget.h"

signin::signin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
}

signin::~signin()
{
    delete ui;
}

void signin::on_returin_clicked()
{
    this->close();
    emit to_home();
}

void signin::retin(const QString rname,const QString rpasswd){
    name=rname;
    password=rpasswd;
    this->show();
}

void signin::on_busin_clicked()
{
    QString nain;
    nain=this->ui->userin->text();
    QString pwdin;
    pwdin=this->ui->passwdin->text();
    if(nain==name&&password==pwdin){
        QMessageBox::warning(this,"signin","signin ok");
    }
    else{
        QMessageBox::warning(this,"signin","signin false");
    }
}
