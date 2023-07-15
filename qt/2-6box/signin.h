#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class signin;
}

class signin : public QWidget
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();

signals:
    void to_home();
public slots:
    void retin(const QString rname,const QString rpasswd);

private slots:
    void on_returin_clicked();

    void on_busin_clicked();

private:
    Ui::signin *ui;
    QString name;
    QString password;
};

#endif // SIGNIN_H
