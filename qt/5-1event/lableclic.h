#ifndef LABLECLIC_H
#define LABLECLIC_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

class lableclic : public QWidget
{
    Q_OBJECT
public:
    explicit lableclic(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *);

signals:
    void click();
public slots:
};

#endif // LABLECLIC_H
