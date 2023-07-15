#include "lableclic.h"

lableclic::lableclic(QWidget *parent) : QWidget (parent)
{

}

void lableclic::mousePressEvent(QMouseEvent *event){
    emit click();
}
