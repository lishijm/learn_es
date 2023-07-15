/********************************************************************************
** Form generated from reading UI file 'aduserf.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADUSERF_H
#define UI_ADUSERF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aduserf
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *adflbtn;
    QPushButton *adsbtn;
    QPushButton *adexitbtn;

    void setupUi(QWidget *aduserf)
    {
        if (aduserf->objectName().isEmpty())
            aduserf->setObjectName(QStringLiteral("aduserf"));
        aduserf->resize(400, 300);
        layoutWidget = new QWidget(aduserf);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 60, 121, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        adflbtn = new QPushButton(layoutWidget);
        adflbtn->setObjectName(QStringLiteral("adflbtn"));

        verticalLayout->addWidget(adflbtn);

        adsbtn = new QPushButton(layoutWidget);
        adsbtn->setObjectName(QStringLiteral("adsbtn"));

        verticalLayout->addWidget(adsbtn);

        adexitbtn = new QPushButton(layoutWidget);
        adexitbtn->setObjectName(QStringLiteral("adexitbtn"));

        verticalLayout->addWidget(adexitbtn);


        retranslateUi(aduserf);

        QMetaObject::connectSlotsByName(aduserf);
    } // setupUi

    void retranslateUi(QWidget *aduserf)
    {
        aduserf->setWindowTitle(QApplication::translate("aduserf", "Form", Q_NULLPTR));
        adflbtn->setText(QApplication::translate("aduserf", "look", Q_NULLPTR));
        adsbtn->setText(QApplication::translate("aduserf", "search", Q_NULLPTR));
        adexitbtn->setText(QApplication::translate("aduserf", "exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aduserf: public Ui_aduserf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADUSERF_H
