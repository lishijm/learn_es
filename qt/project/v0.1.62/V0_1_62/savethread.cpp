#include "savethread.h"

savethread::savethread(QObject *parent) : QThread(parent)
{
    this->width=0;
    this->height=0;
}

void savethread::run(){
    imwrite("./img.jpg",img);
}

void savethread::set_wh(int swidth, int sheight){
    this->width=swidth;
    this->height=sheight;
}

void savethread::recv_mat(const Mat iimg){
    cvtColor(iimg,this->img,COLOR_BGR2RGB);
}
