#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_cul_clicked()
{
    double number_in1=this->ui->in1->text().toDouble();
    double number_in2=this->ui->in2->text().toDouble();

    QString operation=this->ui->math->currentText();

    if(operation=="+"){
        double res=number_in1+number_in2;
        this->ui->result->setText(QString::number(res));
    }
    else if(operation=="-"){
        double res=number_in1-number_in2;
        this->ui->result->setText(QString::number(res));
    }
    else if(operation=="*"){
        double res=number_in1*number_in2;
        this->ui->result->setText(QString::number(res));
    }
    else if(operation=="/"){
        if(fabs(number_in2)<1e-15){
            QMessageBox::warning(this,"cau","除数不能为0");
        }
        double res=number_in1/number_in2;
        this->ui->result->setText(QString::number(res));
    }
}

void Widget::on_cle_clicked()
{
    this->ui->in1->clear();
    this->ui->in2->clear();
    this->ui->result->clear();
}
