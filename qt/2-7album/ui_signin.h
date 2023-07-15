/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signin
{
public:
    QPushButton *busin;
    QLineEdit *userin;
    QLineEdit *passwdin;
    QLabel *label;
    QLabel *label_2;
    QPushButton *returin;

    void setupUi(QWidget *signin)
    {
        if (signin->objectName().isEmpty())
            signin->setObjectName(QStringLiteral("signin"));
        signin->resize(400, 300);
        busin = new QPushButton(signin);
        busin->setObjectName(QStringLiteral("busin"));
        busin->setGeometry(QRect(140, 210, 93, 28));
        userin = new QLineEdit(signin);
        userin->setObjectName(QStringLiteral("userin"));
        userin->setGeometry(QRect(120, 50, 113, 21));
        passwdin = new QLineEdit(signin);
        passwdin->setObjectName(QStringLiteral("passwdin"));
        passwdin->setGeometry(QRect(120, 130, 113, 21));
        label = new QLabel(signin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 72, 15));
        label_2 = new QLabel(signin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 140, 72, 15));
        returin = new QPushButton(signin);
        returin->setObjectName(QStringLiteral("returin"));
        returin->setGeometry(QRect(270, 210, 93, 28));

        retranslateUi(signin);

        QMetaObject::connectSlotsByName(signin);
    } // setupUi

    void retranslateUi(QWidget *signin)
    {
        signin->setWindowTitle(QApplication::translate("signin", "Form", Q_NULLPTR));
        busin->setText(QApplication::translate("signin", "signin", Q_NULLPTR));
        label->setText(QApplication::translate("signin", "username", Q_NULLPTR));
        label_2->setText(QApplication::translate("signin", "passwd", Q_NULLPTR));
        returin->setText(QApplication::translate("signin", "return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class signin: public Ui_signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
