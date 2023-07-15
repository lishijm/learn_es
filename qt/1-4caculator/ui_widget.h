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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QComboBox *math;
    QLabel *label;
    QTextBrowser *result;
    QPushButton *cul;
    QPushButton *cle;
    QLineEdit *in1;
    QLineEdit *in2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1122, 452);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(36);
        Widget->setFont(font);
        math = new QComboBox(Widget);
        math->setObjectName(QStringLiteral("math"));
        math->setGeometry(QRect(510, 60, 91, 81));
        math->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 200, 72, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(72);
        label->setFont(font1);
        label->setTabletTracking(true);
        result = new QTextBrowser(Widget);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(110, 190, 991, 91));
        cul = new QPushButton(Widget);
        cul->setObjectName(QStringLiteral("cul"));
        cul->setGeometry(QRect(200, 310, 291, 111));
        cul->setFont(font);
        cle = new QPushButton(Widget);
        cle->setObjectName(QStringLiteral("cle"));
        cle->setGeometry(QRect(640, 300, 301, 121));
        cle->setFont(font);
        in1 = new QLineEdit(Widget);
        in1->setObjectName(QStringLiteral("in1"));
        in1->setGeometry(QRect(20, 50, 451, 91));
        in2 = new QLineEdit(Widget);
        in2->setObjectName(QStringLiteral("in2"));
        in2->setGeometry(QRect(650, 50, 451, 91));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        math->clear();
        math->insertItems(0, QStringList()
         << QApplication::translate("Widget", "+", Q_NULLPTR)
         << QApplication::translate("Widget", "-", Q_NULLPTR)
         << QApplication::translate("Widget", "*", Q_NULLPTR)
         << QApplication::translate("Widget", "/", Q_NULLPTR)
        );
        label->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
        cul->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", Q_NULLPTR));
        cle->setText(QApplication::translate("Widget", "\346\270\205\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
