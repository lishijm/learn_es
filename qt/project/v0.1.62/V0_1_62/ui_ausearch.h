/********************************************************************************
** Form generated from reading UI file 'ausearch.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUSEARCH_H
#define UI_AUSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ausearch
{
public:
    QLabel *nl;
    QLineEdit *nameline;
    QLabel *x;
    QPushButton *asearbtn;
    QPushButton *asclbtn;
    QListWidget *scres;

    void setupUi(QWidget *ausearch)
    {
        if (ausearch->objectName().isEmpty())
            ausearch->setObjectName(QStringLiteral("ausearch"));
        ausearch->resize(800, 600);
        nl = new QLabel(ausearch);
        nl->setObjectName(QStringLiteral("nl"));
        nl->setGeometry(QRect(10, 50, 72, 15));
        nameline = new QLineEdit(ausearch);
        nameline->setObjectName(QStringLiteral("nameline"));
        nameline->setGeometry(QRect(20, 80, 113, 21));
        x = new QLabel(ausearch);
        x->setObjectName(QStringLiteral("x"));
        x->setGeometry(QRect(40, 240, 72, 20));
        asearbtn = new QPushButton(ausearch);
        asearbtn->setObjectName(QStringLiteral("asearbtn"));
        asearbtn->setGeometry(QRect(30, 120, 93, 28));
        asclbtn = new QPushButton(ausearch);
        asclbtn->setObjectName(QStringLiteral("asclbtn"));
        asclbtn->setGeometry(QRect(680, 540, 93, 28));
        scres = new QListWidget(ausearch);
        scres->setObjectName(QStringLiteral("scres"));
        scres->setGeometry(QRect(160, 20, 481, 551));

        retranslateUi(ausearch);

        QMetaObject::connectSlotsByName(ausearch);
    } // setupUi

    void retranslateUi(QWidget *ausearch)
    {
        ausearch->setWindowTitle(QApplication::translate("ausearch", "Form", Q_NULLPTR));
        nl->setText(QApplication::translate("ausearch", "name", Q_NULLPTR));
        x->setText(QApplication::translate("ausearch", "TextLabel", Q_NULLPTR));
        asearbtn->setText(QApplication::translate("ausearch", "search", Q_NULLPTR));
        asclbtn->setText(QApplication::translate("ausearch", "cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ausearch: public Ui_ausearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUSEARCH_H
