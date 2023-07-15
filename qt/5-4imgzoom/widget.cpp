#include <QDebug>
#include "widget.h"

picscale::picscale(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,600);

    this->maxLevel = 0;
    this->xLevel = 0;
    this->yLevel = 0;

    this->picLabel = new QLabel(this);
    this->picLabel->resize(this->width(),this->height());
    this->picLabel->setPixmap(QPixmap("./1.png"));
    this->picLabel->setScaledContents(true);
}

void picscale::paintEvent(QPaintEvent *event)
{
    this->picLabel->resize(this->width()+200*this->maxLevel,this->height()+150*this->maxLevel);
}

void picscale::mousePressEvent(QMouseEvent *event)
{
    this->mousePoint = event->pos();
    qDebug() << this->picLabel->pos();
}

void picscale::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        if((this->picLabel->pos().x()+(event->pos().x()-this->mousePoint.x()))<0&&
                (this->picLabel->pos().y()+(event->pos().y()-this->mousePoint.y()))<0&&
                ((this->picLabel->pos().x()+this->picLabel->width())+(event->pos().x()-mousePoint.x()))>this->width()&&
                ((this->picLabel->pos().y()+this->picLabel->height())+(event->pos().y()-mousePoint.y()))>this->height())
        {
            this->picLabel->move(this->picLabel->pos()+(event->pos()-this->mousePoint));
            this->mousePoint = event->pos();
        }
    }
}

void picscale::wheelEvent(QWheelEvent *event)
{
    this->mousePoint = event->pos();


    if(event->delta()>0)
    {
        if(this->maxLevel < 10)
        {
            this->maxLevel++;
            //做了一个等比例锚点
            this->picLabel->move((double)mousePoint.x()-((double)mousePoint.x()*((double)(this->width()+200*maxLevel)/(double)this->width())),
                                 (double)mousePoint.y()-((double)mousePoint.y()*((double)(this->height()+150*maxLevel)/(double)this->height())));
        }
    }
    else
    {
        if(this->maxLevel > 0)
        {
            this->maxLevel--;
            this->picLabel->move((double)mousePoint.x()-((double)mousePoint.x()*((double)(this->width()+200*maxLevel)/(double)this->width())),
                                 (double)mousePoint.y()-((double)mousePoint.y()*((double)(this->height()+150*maxLevel)/(double)this->height())));
        }
    }
}
