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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QSlider *volumn;
    QSlider *playtime;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *songname;
    QLabel *songtime;
    QHBoxLayout *horizontalLayout;
    QPushButton *play_btn;
    QPushButton *psu_btn;
    QPushButton *chs_btn;
    QLabel *label;
    QPushButton *up_btn;
    QPushButton *dow_btn;
    QListWidget *listWidget;
    QPushButton *sp_btn;
    QPushButton *slp_btn;
    QPushButton *lsp_btn;
    QPushButton *llp_btn;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(797, 500);
        volumn = new QSlider(Widget);
        volumn->setObjectName(QStringLiteral("volumn"));
        volumn->setGeometry(QRect(570, 460, 160, 22));
        volumn->setOrientation(Qt::Horizontal);
        playtime = new QSlider(Widget);
        playtime->setObjectName(QStringLiteral("playtime"));
        playtime->setGeometry(QRect(280, 410, 451, 21));
        playtime->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 10, 451, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        songname = new QLabel(layoutWidget);
        songname->setObjectName(QStringLiteral("songname"));

        horizontalLayout_2->addWidget(songname);

        songtime = new QLabel(layoutWidget);
        songtime->setObjectName(QStringLiteral("songtime"));

        horizontalLayout_2->addWidget(songtime);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        play_btn = new QPushButton(layoutWidget);
        play_btn->setObjectName(QStringLiteral("play_btn"));

        horizontalLayout->addWidget(play_btn);

        psu_btn = new QPushButton(layoutWidget);
        psu_btn->setObjectName(QStringLiteral("psu_btn"));

        horizontalLayout->addWidget(psu_btn);

        chs_btn = new QPushButton(layoutWidget);
        chs_btn->setObjectName(QStringLiteral("chs_btn"));

        horizontalLayout->addWidget(chs_btn);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(490, 460, 72, 15));
        up_btn = new QPushButton(Widget);
        up_btn->setObjectName(QStringLiteral("up_btn"));
        up_btn->setGeometry(QRect(20, 450, 93, 28));
        dow_btn = new QPushButton(Widget);
        dow_btn->setObjectName(QStringLiteral("dow_btn"));
        dow_btn->setGeometry(QRect(170, 450, 93, 28));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 256, 421));
        sp_btn = new QPushButton(Widget);
        sp_btn->setObjectName(QStringLiteral("sp_btn"));
        sp_btn->setGeometry(QRect(740, 140, 51, 41));
        slp_btn = new QPushButton(Widget);
        slp_btn->setObjectName(QStringLiteral("slp_btn"));
        slp_btn->setGeometry(QRect(740, 190, 51, 41));
        lsp_btn = new QPushButton(Widget);
        lsp_btn->setObjectName(QStringLiteral("lsp_btn"));
        lsp_btn->setGeometry(QRect(740, 240, 51, 41));
        llp_btn = new QPushButton(Widget);
        llp_btn->setObjectName(QStringLiteral("llp_btn"));
        llp_btn->setGeometry(QRect(740, 290, 51, 41));
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(280, 100, 451, 291));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        songname->setText(QApplication::translate("Widget", "name", Q_NULLPTR));
        songtime->setText(QApplication::translate("Widget", "time", Q_NULLPTR));
        play_btn->setText(QApplication::translate("Widget", "play", Q_NULLPTR));
        psu_btn->setText(QApplication::translate("Widget", "pause", Q_NULLPTR));
        chs_btn->setText(QApplication::translate("Widget", "add", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "volume", Q_NULLPTR));
        up_btn->setText(QApplication::translate("Widget", "up", Q_NULLPTR));
        dow_btn->setText(QApplication::translate("Widget", "down", Q_NULLPTR));
        sp_btn->setText(QApplication::translate("Widget", "SP", Q_NULLPTR));
        slp_btn->setText(QApplication::translate("Widget", "SLP", Q_NULLPTR));
        lsp_btn->setText(QApplication::translate("Widget", "LSP", Q_NULLPTR));
        llp_btn->setText(QApplication::translate("Widget", "LLP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
