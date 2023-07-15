/********************************************************************************
** Form generated from reading UI file 'nmusersel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NMUSERSEL_H
#define UI_NMUSERSEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nmusersel
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *nmselinbtn;
    QPushButton *nmselupbtn;

    void setupUi(QWidget *nmusersel)
    {
        if (nmusersel->objectName().isEmpty())
            nmusersel->setObjectName(QStringLiteral("nmusersel"));
        nmusersel->resize(400, 300);
        widget = new QWidget(nmusersel);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(140, 50, 131, 171));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nmselinbtn = new QPushButton(widget);
        nmselinbtn->setObjectName(QStringLiteral("nmselinbtn"));

        verticalLayout->addWidget(nmselinbtn);

        nmselupbtn = new QPushButton(widget);
        nmselupbtn->setObjectName(QStringLiteral("nmselupbtn"));

        verticalLayout->addWidget(nmselupbtn);


        retranslateUi(nmusersel);

        QMetaObject::connectSlotsByName(nmusersel);
    } // setupUi

    void retranslateUi(QWidget *nmusersel)
    {
        nmusersel->setWindowTitle(QApplication::translate("nmusersel", "Form", Q_NULLPTR));
        nmselinbtn->setText(QApplication::translate("nmusersel", "sign in", Q_NULLPTR));
        nmselupbtn->setText(QApplication::translate("nmusersel", "sign up", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class nmusersel: public Ui_nmusersel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NMUSERSEL_H
