#include "signup.h"
#include "ui_signup.h"
#include "widget.h"
#include "sqlite.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    sq1.open("./data/user.db");
}

signup::~signup()
{
    delete ui;
}

void signup::on_returnup_clicked()
{
    this->close();
    emit to_home();
}

void signup::on_buup_clicked()
{
    QString naup;
    naup=this->ui->userup->text();
    QString pwdup;
    pwdup=this->ui->passup->text();
    QString pwdupr;
    pwdupr=this->ui->passupr->text();
    string nasq,pwdsq;
    nasq=naup.toStdString();
    pwdsq=pwdup.toStdString();
    string sql="insert into user_information values(NULL,'"+nasq+"','"+pwdsq+"','n');";
    if(pwdup==pwdupr){
        if(sq1.signin(sql,naup.toStdString())){
            QMessageBox::warning(this,"signup","sign up ok");
        }
        else{
            QMessageBox::warning(this,"signup","user name has exist");
        }
    }
    else{
        QMessageBox::warning(this,"signup","password isn't right");
    }
}
