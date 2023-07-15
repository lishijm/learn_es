#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDir>
#include <QListWidget>
#include <QFileInfoList>
#include <QStringList>
#include <QListWidget>
#include <QProcess>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void dir_show();
    ~Widget();
#if 1
private slots:
    void on_ft_dir_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
#endif
private:
    Ui::Widget *ui;
    QDir *dirctp;
    QString path;
};

#endif // WIDGET_H
