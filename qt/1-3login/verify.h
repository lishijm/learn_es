#ifndef VERIFY_H
#define VERIFY_H

#include <QFrame>
#include <QString>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QTime>
#include <QChar>
#include <QPainter>
#include <QtGlobal>

class verify : virtual public QFrame
{
    Q_OBJECT
public:
    verify();
    void generateRandNum();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    QString code;
};

#endif // VERIFY_H
