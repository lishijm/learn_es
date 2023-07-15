#include "signin.h"
#include "ui_signin.h"
#include "widget.h"

signin::signin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
    sq1.open("./data/user.db");
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

void signin::on_busin_clicked()
{
    QString nain;
    nain=this->ui->userin->text();
    QString pwdin;
    pwdin=this->ui->passwdin->text();
    string nasq=nain.toStdString();
    string pwdsq=pwdin.toStdString();
    if(sq1.login(nasq,pwdsq)){
        QMessageBox::warning(this,"signin","signin ok");
        this->close();
        emit to_album();

    }
    else{
        QMessageBox::warning(this,"signin","signin false");
    }
}
