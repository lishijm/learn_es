/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *buin;
    QPushButton *buup;
    QPushButton *bue;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        buin = new QPushButton(Widget);
        buin->setObjectName(QStringLiteral("buin"));
        buin->setGeometry(QRect(140, 60, 93, 28));
        buup = new QPushButton(Widget);
        buup->setObjectName(QStringLiteral("buup"));
        buup->setGeometry(QRect(140, 140, 93, 28));
        bue = new QPushButton(Widget);
        bue->setObjectName(QStringLiteral("bue"));
        bue->setGeometry(QRect(140, 220, 93, 28));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        buin->setText(QApplication::translate("Widget", "sign in", Q_NULLPTR));
        buup->setText(QApplication::translate("Widget", "sign up", Q_NULLPTR));
        bue->setText(QApplication::translate("Widget", "exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
