#include "aduserf.h"
#include "ui_aduserf.h"

aduserf::aduserf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aduserf)
{
    ui->setupUi(this);
}

aduserf::~aduserf()
{
    delete ui;
}

void aduserf::resg(QTcpSocket *tmpsokt)
{
    netsokt=tmpsokt;
}

void aduserf::on_adflbtn_clicked()
{
    emit sgskalk(netsokt);
    emit to_look();
    this->close();
}

void aduserf::on_adsbtn_clicked()
{
    emit sgskasc(netsokt);
    emit to_search();
    this->close();
}



void aduserf::on_adexitbtn_clicked()
{
    emit to_home();
    this->close();
}
