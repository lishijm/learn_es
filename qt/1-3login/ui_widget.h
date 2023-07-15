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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username;
    QLineEdit *passwd;
    QPushButton *login;
    QLineEdit *check;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 60, 72, 31));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 130, 72, 31));
        label_2->setFont(font);
        username = new QLineEdit(Widget);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(130, 60, 221, 31));
        passwd = new QLineEdit(Widget);
        passwd->setObjectName(QStringLiteral("passwd"));
        passwd->setGeometry(QRect(130, 130, 221, 31));
        login = new QPushButton(Widget);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(150, 240, 93, 41));
        login->setFont(font);
        check = new QLineEdit(Widget);
        check->setObjectName(QStringLiteral("check"));
        check->setGeometry(QRect(40, 190, 113, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\345\257\206\347\240\201", Q_NULLPTR));
        login->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
