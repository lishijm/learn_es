/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

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

class Ui_signup
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *userup;
    QLineEdit *passup;
    QLineEdit *passupr;
    QPushButton *buup;
    QPushButton *returnup;

    void setupUi(QWidget *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QStringLiteral("signup"));
        signup->resize(400, 300);
        label = new QLabel(signup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 72, 15));
        label_2 = new QLabel(signup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 100, 72, 15));
        label_3 = new QLabel(signup);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 150, 72, 15));
        userup = new QLineEdit(signup);
        userup->setObjectName(QStringLiteral("userup"));
        userup->setGeometry(QRect(170, 50, 113, 21));
        passup = new QLineEdit(signup);
        passup->setObjectName(QStringLiteral("passup"));
        passup->setGeometry(QRect(170, 90, 113, 21));
        passupr = new QLineEdit(signup);
        passupr->setObjectName(QStringLiteral("passupr"));
        passupr->setGeometry(QRect(170, 140, 113, 21));
        buup = new QPushButton(signup);
        buup->setObjectName(QStringLiteral("buup"));
        buup->setGeometry(QRect(150, 240, 93, 28));
        returnup = new QPushButton(signup);
        returnup->setObjectName(QStringLiteral("returnup"));
        returnup->setGeometry(QRect(280, 240, 93, 28));

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QWidget *signup)
    {
        signup->setWindowTitle(QApplication::translate("signup", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("signup", "username", Q_NULLPTR));
        label_2->setText(QApplication::translate("signup", "passwd", Q_NULLPTR));
        label_3->setText(QApplication::translate("signup", "rpasswd", Q_NULLPTR));
        buup->setText(QApplication::translate("signup", "signup", Q_NULLPTR));
        returnup->setText(QApplication::translate("signup", "return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
