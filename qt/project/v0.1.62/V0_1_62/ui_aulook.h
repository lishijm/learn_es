/********************************************************************************
** Form generated from reading UI file 'aulook.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AULOOK_H
#define UI_AULOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aulook
{
public:
    QPushButton *lkrbtn;
    QListWidget *lkres;

    void setupUi(QWidget *aulook)
    {
        if (aulook->objectName().isEmpty())
            aulook->setObjectName(QStringLiteral("aulook"));
        aulook->resize(276, 600);
        lkrbtn = new QPushButton(aulook);
        lkrbtn->setObjectName(QStringLiteral("lkrbtn"));
        lkrbtn->setGeometry(QRect(160, 560, 93, 28));
        lkres = new QListWidget(aulook);
        lkres->setObjectName(QStringLiteral("lkres"));
        lkres->setGeometry(QRect(20, 20, 231, 511));

        retranslateUi(aulook);

        QMetaObject::connectSlotsByName(aulook);
    } // setupUi

    void retranslateUi(QWidget *aulook)
    {
        aulook->setWindowTitle(QApplication::translate("aulook", "Form", Q_NULLPTR));
        lkrbtn->setText(QApplication::translate("aulook", "return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aulook: public Ui_aulook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AULOOK_H
