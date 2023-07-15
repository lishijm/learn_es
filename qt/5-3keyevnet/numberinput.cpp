#include "numberinput.h"

numberinput::numberinput(QWidget *parent) : QWidget(parent)
{

}

void numberinput::keypressevent(QKeyEvent *event){
    if(event->text()>='0'&&event->key()<='9'){

    }
}
