#ifndef NUMBERINPUT_H
#define NUMBERINPUT_H

#include <QObject>
#include <QWidget>
#include <QKeyEvent>

class numberinput : public QWidget
{
    Q_OBJECT
public:
    explicit numberinput(QWidget *parent = nullptr);

    void keypressevent(QKeyEvent *event);
signals:

public slots:
};

#endif // NUMBERINPUT_H
