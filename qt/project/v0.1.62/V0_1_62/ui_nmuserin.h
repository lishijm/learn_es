/********************************************************************************
** Form generated from reading UI file 'nmuserin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NMUSERIN_H
#define UI_NMUSERIN_H

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

class Ui_nmuserin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *inunl;
    QLineEdit *nminnameline;
    QHBoxLayout *horizontalLayout_2;
    QLabel *inpl;
    QLineEdit *nminpasswdline;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *nminbtn;
    QPushButton *nminclbtn;
    QLabel *caml;

    void setupUi(QWidget *nmuserin)
    {
        if (nmuserin->objectName().isEmpty())
            nmuserin->setObjectName(QStringLiteral("nmuserin"));
        nmuserin->resize(800, 300);
        layoutWidget = new QWidget(nmuserin);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(440, 20, 331, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        inunl = new QLabel(layoutWidget);
        inunl->setObjectName(QStringLiteral("inunl"));

        horizontalLayout->addWidget(inunl);

        nminnameline = new QLineEdit(layoutWidget);
        nminnameline->setObjectName(QStringLiteral("nminnameline"));

        horizontalLayout->addWidget(nminnameline);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        inpl = new QLabel(layoutWidget);
        inpl->setObjectName(QStringLiteral("inpl"));

        horizontalLayout_2->addWidget(inpl);

        nminpasswdline = new QLineEdit(layoutWidget);
        nminpasswdline->setObjectName(QStringLiteral("nminpasswdline"));

        horizontalLayout_2->addWidget(nminpasswdline);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        nminbtn = new QPushButton(layoutWidget);
        nminbtn->setObjectName(QStringLiteral("nminbtn"));

        horizontalLayout_3->addWidget(nminbtn);

        nminclbtn = new QPushButton(layoutWidget);
        nminclbtn->setObjectName(QStringLiteral("nminclbtn"));

        horizontalLayout_3->addWidget(nminclbtn);


        verticalLayout->addLayout(horizontalLayout_3);

        caml = new QLabel(nmuserin);
        caml->setObjectName(QStringLiteral("caml"));
        caml->setGeometry(QRect(30, 30, 320, 240));

        retranslateUi(nmuserin);

        QMetaObject::connectSlotsByName(nmuserin);
    } // setupUi

    void retranslateUi(QWidget *nmuserin)
    {
        nmuserin->setWindowTitle(QApplication::translate("nmuserin", "Form", Q_NULLPTR));
        inunl->setText(QApplication::translate("nmuserin", "user name", Q_NULLPTR));
        inpl->setText(QApplication::translate("nmuserin", "password", Q_NULLPTR));
        nminbtn->setText(QApplication::translate("nmuserin", "sign in", Q_NULLPTR));
        nminclbtn->setText(QApplication::translate("nmuserin", "cancel", Q_NULLPTR));
        caml->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class nmuserin: public Ui_nmuserin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NMUSERIN_H
