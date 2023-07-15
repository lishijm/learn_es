/********************************************************************************
** Form generated from reading UI file 'album.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALBUM_H
#define UI_ALBUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_album
{
public:
    QLCDNumber *time1;
    QLabel *imgshow;
    QPushButton *upbut;
    QPushButton *downbut;
    QPushButton *rebut;

    void setupUi(QWidget *album)
    {
        if (album->objectName().isEmpty())
            album->setObjectName(QStringLiteral("album"));
        album->resize(1024, 768);
        time1 = new QLCDNumber(album);
        time1->setObjectName(QStringLiteral("time1"));
        time1->setGeometry(QRect(20, 70, 981, 41));
        time1->setMode(QLCDNumber::Dec);
        imgshow = new QLabel(album);
        imgshow->setObjectName(QStringLiteral("imgshow"));
        imgshow->setGeometry(QRect(192, 360, 640, 360));
        upbut = new QPushButton(album);
        upbut->setObjectName(QStringLiteral("upbut"));
        upbut->setGeometry(QRect(34, 520, 93, 28));
        downbut = new QPushButton(album);
        downbut->setObjectName(QStringLiteral("downbut"));
        downbut->setGeometry(QRect(900, 520, 90, 28));
        rebut = new QPushButton(album);
        rebut->setObjectName(QStringLiteral("rebut"));
        rebut->setGeometry(QRect(920, 10, 93, 28));

        retranslateUi(album);

        QMetaObject::connectSlotsByName(album);
    } // setupUi

    void retranslateUi(QWidget *album)
    {
        album->setWindowTitle(QApplication::translate("album", "Form", Q_NULLPTR));
        imgshow->setText(QApplication::translate("album", "TextLabel", Q_NULLPTR));
        upbut->setText(QApplication::translate("album", "\344\270\212", Q_NULLPTR));
        downbut->setText(QApplication::translate("album", "\344\270\213", Q_NULLPTR));
        rebut->setText(QApplication::translate("album", "return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class album: public Ui_album {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALBUM_H
