/********************************************************************************
** Form generated from reading UI file 'setnet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETNET_H
#define UI_SETNET_H

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

class Ui_setnet
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *ipl;
    QLineEdit *ipline;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ptl;
    QLineEdit *portline;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *nsconbtn;
    QPushButton *nsclbtn;

    void setupUi(QWidget *setnet)
    {
        if (setnet->objectName().isEmpty())
            setnet->setObjectName(QStringLiteral("setnet"));
        setnet->resize(400, 300);
        layoutWidget = new QWidget(setnet);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 20, 321, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ipl = new QLabel(layoutWidget);
        ipl->setObjectName(QStringLiteral("ipl"));

        horizontalLayout->addWidget(ipl);

        ipline = new QLineEdit(layoutWidget);
        ipline->setObjectName(QStringLiteral("ipline"));

        horizontalLayout->addWidget(ipline);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ptl = new QLabel(layoutWidget);
        ptl->setObjectName(QStringLiteral("ptl"));

        horizontalLayout_2->addWidget(ptl);

        portline = new QLineEdit(layoutWidget);
        portline->setObjectName(QStringLiteral("portline"));

        horizontalLayout_2->addWidget(portline);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        nsconbtn = new QPushButton(layoutWidget);
        nsconbtn->setObjectName(QStringLiteral("nsconbtn"));

        horizontalLayout_3->addWidget(nsconbtn);

        nsclbtn = new QPushButton(layoutWidget);
        nsclbtn->setObjectName(QStringLiteral("nsclbtn"));

        horizontalLayout_3->addWidget(nsclbtn);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(setnet);

        QMetaObject::connectSlotsByName(setnet);
    } // setupUi

    void retranslateUi(QWidget *setnet)
    {
        setnet->setWindowTitle(QApplication::translate("setnet", "Form", Q_NULLPTR));
        ipl->setText(QApplication::translate("setnet", "IP:", Q_NULLPTR));
        ipline->setText(QApplication::translate("setnet", "192.168.8.226", Q_NULLPTR));
        ptl->setText(QApplication::translate("setnet", "PORT:", Q_NULLPTR));
        portline->setText(QApplication::translate("setnet", "5050", Q_NULLPTR));
        nsconbtn->setText(QApplication::translate("setnet", "connect", Q_NULLPTR));
        nsclbtn->setText(QApplication::translate("setnet", "cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class setnet: public Ui_setnet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETNET_H
