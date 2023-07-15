#include "signup.h"
#include "ui_signup.h"
#include "widget.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
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
    if(pwdup==pwdupr){
        emit to_in(naup,pwdup);
        this->close();
    }
    else{
        QMessageBox::warning(this,"signup","password isn't right");
    }
}
