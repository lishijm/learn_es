#include "showthread.h"

showthread::showthread(QObject *parent) : QThread(parent)
{
    this->flag=0;
}

void showthread::run(){
    VideoCapture capture(0);

    Mat dst,mat;
    for (;;) {
        capture>>mat;
        flip(mat,dst,1);
        emit send_img(this->mat2qim(dst));
        emit send_mat(dst);

        waitKey(1);
        if(this->flag==1){
            break;
        }
    }
    capture.release();
}

QImage showthread::mat2qim(Mat &mat){
    cvtColor(mat,mat,COLOR_BGR2RGB);
    QImage qim((const unsigned char *)mat.data, mat.cols, mat.rows, mat.step,QImage::Format_RGB888);
    return qim;
}

void showthread::set_flag(int sflag)
{
    this->flag=sflag;
}
