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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *upunl;
    QLineEdit *upnameline;
    QHBoxLayout *horizontalLayout_2;
    QLabel *uppl;
    QLineEdit *uppwdline;
    QHBoxLayout *horizontalLayout_3;
    QLabel *uprpl;
    QLineEdit *uprpwdline;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *upupbtn;
    QPushButton *upclbtn;

    void setupUi(QWidget *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QStringLiteral("signup"));
        signup->resize(400, 300);
        widget = new QWidget(signup);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 361, 261));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        upunl = new QLabel(widget);
        upunl->setObjectName(QStringLiteral("upunl"));

        horizontalLayout->addWidget(upunl);

        upnameline = new QLineEdit(widget);
        upnameline->setObjectName(QStringLiteral("upnameline"));

        horizontalLayout->addWidget(upnameline);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        uppl = new QLabel(widget);
        uppl->setObjectName(QStringLiteral("uppl"));

        horizontalLayout_2->addWidget(uppl);

        uppwdline = new QLineEdit(widget);
        uppwdline->setObjectName(QStringLiteral("uppwdline"));

        horizontalLayout_2->addWidget(uppwdline);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        uprpl = new QLabel(widget);
        uprpl->setObjectName(QStringLiteral("uprpl"));

        horizontalLayout_3->addWidget(uprpl);

        uprpwdline = new QLineEdit(widget);
        uprpwdline->setObjectName(QStringLiteral("uprpwdline"));

        horizontalLayout_3->addWidget(uprpwdline);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        upupbtn = new QPushButton(widget);
        upupbtn->setObjectName(QStringLiteral("upupbtn"));

        horizontalLayout_4->addWidget(upupbtn);

        upclbtn = new QPushButton(widget);
        upclbtn->setObjectName(QStringLiteral("upclbtn"));

        horizontalLayout_4->addWidget(upclbtn);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QWidget *signup)
    {
        signup->setWindowTitle(QApplication::translate("signup", "Form", Q_NULLPTR));
        upunl->setText(QApplication::translate("signup", "user name", Q_NULLPTR));
        uppl->setText(QApplication::translate("signup", "password", Q_NULLPTR));
        uprpl->setText(QApplication::translate("signup", "re password", Q_NULLPTR));
        upupbtn->setText(QApplication::translate("signup", "sign up", Q_NULLPTR));
        upclbtn->setText(QApplication::translate("signup", "cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
