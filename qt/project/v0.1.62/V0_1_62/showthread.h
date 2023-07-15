#ifndef SHOWTHREAD_H
#define SHOWTHREAD_H

#include <QObject>
#include <QThread>
#include <QImage>
#include <opencv2/opencv.hpp>

using namespace cv;

class showthread : public QThread
{
    Q_OBJECT
public:
    explicit showthread(QObject *parent = nullptr);

    void run();

    QImage mat2qim(Mat &);

    void set_flag(int flag);

signals:
    void send_img(const QImage &);

    void send_mat(const Mat &);

public slots:


private:
    int flag;
};

#endif // SHOWTHREAD_H
