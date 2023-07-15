#ifndef SAVETHREAD_H
#define SAVETHREAD_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <QThread>

using namespace cv;

class savethread : public QThread
{
    Q_OBJECT
public:
    explicit savethread(QObject *parent = nullptr);

    void run();

    void set_wh(int,int);

signals:

public slots:
    void recv_mat(const Mat);

private:
    Mat img;

    int width,height;

};

#endif // SAVETHREAD_H
