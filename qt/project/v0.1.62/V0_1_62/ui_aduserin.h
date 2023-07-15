/********************************************************************************
** Form generated from reading UI file 'aduserin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADUSERIN_H
#define UI_ADUSERIN_H

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

class Ui_aduserin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *adunl;
    QLineEdit *adnameline;
    QHBoxLayout *horizontalLayout_2;
    QLabel *adpl;
    QLineEdit *adpwdline;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *adsinbtn;
    QPushButton *adclbtn;

    void setupUi(QWidget *aduserin)
    {
        if (aduserin->objectName().isEmpty())
            aduserin->setObjectName(QStringLiteral("aduserin"));
        aduserin->resize(400, 300);
        layoutWidget = new QWidget(aduserin);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 341, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        adunl = new QLabel(layoutWidget);
        adunl->setObjectName(QStringLiteral("adunl"));

        horizontalLayout->addWidget(adunl);

        adnameline = new QLineEdit(layoutWidget);
        adnameline->setObjectName(QStringLiteral("adnameline"));

        horizontalLayout->addWidget(adnameline);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        adpl = new QLabel(layoutWidget);
        adpl->setObjectName(QStringLiteral("adpl"));

        horizontalLayout_2->addWidget(adpl);

        adpwdline = new QLineEdit(layoutWidget);
        adpwdline->setObjectName(QStringLiteral("adpwdline"));

        horizontalLayout_2->addWidget(adpwdline);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        adsinbtn = new QPushButton(layoutWidget);
        adsinbtn->setObjectName(QStringLiteral("adsinbtn"));

        horizontalLayout_3->addWidget(adsinbtn);

        adclbtn = new QPushButton(layoutWidget);
        adclbtn->setObjectName(QStringLiteral("adclbtn"));

        horizontalLayout_3->addWidget(adclbtn);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(aduserin);

        QMetaObject::connectSlotsByName(aduserin);
    } // setupUi

    void retranslateUi(QWidget *aduserin)
    {
        aduserin->setWindowTitle(QApplication::translate("aduserin", "Form", Q_NULLPTR));
        adunl->setText(QApplication::translate("aduserin", "user name", Q_NULLPTR));
        adnameline->setText(QApplication::translate("aduserin", "admin", Q_NULLPTR));
        adpl->setText(QApplication::translate("aduserin", "password", Q_NULLPTR));
        adpwdline->setText(QApplication::translate("aduserin", "root", Q_NULLPTR));
        adsinbtn->setText(QApplication::translate("aduserin", "sign in", Q_NULLPTR));
        adclbtn->setText(QApplication::translate("aduserin", "cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aduserin: public Ui_aduserin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADUSERIN_H
