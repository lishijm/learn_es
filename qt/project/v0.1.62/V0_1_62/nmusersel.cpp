#include "nmusersel.h"
#include "ui_nmusersel.h"

nmusersel::nmusersel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nmusersel)
{
    ui->setupUi(this);
}

nmusersel::~nmusersel()
{
    delete ui;
}

void nmusersel::on_nmselinbtn_clicked()
{
    emit sgsksin(netsokt);
    emit to_sin();
    this->close();
}

void nmusersel::on_nmselupbtn_clicked()
{
    emit sgsksup(netsokt);
    emit to_sup();
    this->close();
}

void nmusersel::resg(QTcpSocket *tmpsokt){
    netsokt=tmpsokt;
}
