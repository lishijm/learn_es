#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QPoint>
#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>

class picscale : public QWidget
{
    Q_OBJECT
public:
    explicit picscale(QWidget *parent = 0);
    QLabel *picLabel;
    int maxLevel;
    double xLevel;
    double yLevel;
    QPoint mousePoint;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
signals:

public slots:
};

#endif // WIDGET_H
