/********************************************************************************
** Form generated from reading UI file 'MyCPlus.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCPLUS_H
#define UI_MYCPLUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyCPlusClass
{
public:
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *pageSet;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *pageGame;
    QWidget *Board;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_18;
    QLabel *label_15;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *widget;
    QLabel *label_17;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;

    void setupUi(QWidget *MyCPlusClass)
    {
        if (MyCPlusClass->objectName().isEmpty())
            MyCPlusClass->setObjectName("MyCPlusClass");
        MyCPlusClass->setEnabled(true);
        MyCPlusClass->resize(890, 528);
        MyCPlusClass->setAutoFillBackground(false);
        MyCPlusClass->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(MyCPlusClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(MyCPlusClass);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setAutoFillBackground(true);
        pageSet = new QWidget();
        pageSet->setObjectName("pageSet");
        pageSet->setAutoFillBackground(false);
        pageSet->setStyleSheet(QString::fromUtf8("#pageSet{\n"
"	background:url(\":/images/back2.jpg\");\n"
"	background-size:100% 100%;\n"
"}"));
        pushButton_2 = new QPushButton(pageSet);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(460, 420, 111, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223")});
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";\n"
"background-color:rgb(235, 217, 129);\n"
"border-radius:10px;\n"
"color:rgb(0, 0, 0)"));
        pushButton_3 = new QPushButton(pageSet);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setEnabled(true);
        pushButton_3->setGeometry(QRect(260, 420, 111, 41));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(235, 217, 129, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(0, 0, 0, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        pushButton_3->setPalette(palette);
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";\n"
"background-color:rgb(235, 217, 129);\n"
"border-radius:10px;\n"
"color:rgb(0, 0, 0)"));
        layoutWidget = new QWidget(pageSet);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 100, 831, 261));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/timg.jpg")));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(pageSet);
        pageGame = new QWidget();
        pageGame->setObjectName("pageGame");
        pageGame->setStyleSheet(QString::fromUtf8("#pageGame{\n"
"	background-color:#faf8ef;\n"
"}"));
        Board = new QWidget(pageGame);
        Board->setObjectName("Board");
        Board->setGeometry(QRect(20, 50, 441, 441));
        Board->setLayoutDirection(Qt::LeftToRight);
        Board->setAutoFillBackground(false);
        Board->setStyleSheet(QString::fromUtf8("#Board{\n"
"background-color:#bbada0;\n"
"border:2px solid rgb(255, 223, 184);\n"
"border-radius:10px;\n"
"}"));
        gridLayout = new QGridLayout(Board);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(Board);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(Board);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);
        label_3->setLayoutDirection(Qt::RightToLeft);
        label_3->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(Board);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);
        label_4->setLayoutDirection(Qt::RightToLeft);
        label_4->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_5 = new QLabel(Board);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);
        label_5->setLayoutDirection(Qt::RightToLeft);
        label_5->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 3, 1, 1);

        label_7 = new QLabel(Board);
        label_7->setObjectName("label_7");
        label_7->setFont(font1);
        label_7->setLayoutDirection(Qt::RightToLeft);
        label_7->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(Board);
        label_8->setObjectName("label_8");
        label_8->setFont(font1);
        label_8->setLayoutDirection(Qt::RightToLeft);
        label_8->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 1, 1, 1, 1);

        label_9 = new QLabel(Board);
        label_9->setObjectName("label_9");
        label_9->setFont(font1);
        label_9->setLayoutDirection(Qt::RightToLeft);
        label_9->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 1, 2, 1, 1);

        label_6 = new QLabel(Board);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);
        label_6->setLayoutDirection(Qt::RightToLeft);
        label_6->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 3, 1, 1);

        label_10 = new QLabel(Board);
        label_10->setObjectName("label_10");
        label_10->setFont(font1);
        label_10->setLayoutDirection(Qt::RightToLeft);
        label_10->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        label_12 = new QLabel(Board);
        label_12->setObjectName("label_12");
        label_12->setFont(font1);
        label_12->setLayoutDirection(Qt::RightToLeft);
        label_12->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 2, 1, 1, 1);

        label_11 = new QLabel(Board);
        label_11->setObjectName("label_11");
        label_11->setFont(font1);
        label_11->setLayoutDirection(Qt::RightToLeft);
        label_11->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 2, 2, 1, 1);

        label_13 = new QLabel(Board);
        label_13->setObjectName("label_13");
        label_13->setFont(font1);
        label_13->setLayoutDirection(Qt::RightToLeft);
        label_13->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 2, 3, 1, 1);

        label_16 = new QLabel(Board);
        label_16->setObjectName("label_16");
        label_16->setFont(font1);
        label_16->setLayoutDirection(Qt::RightToLeft);
        label_16->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_16, 3, 0, 1, 1);

        label_14 = new QLabel(Board);
        label_14->setObjectName("label_14");
        label_14->setFont(font1);
        label_14->setLayoutDirection(Qt::RightToLeft);
        label_14->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_14, 3, 1, 1, 1);

        label_18 = new QLabel(Board);
        label_18->setObjectName("label_18");
        label_18->setFont(font1);
        label_18->setLayoutDirection(Qt::RightToLeft);
        label_18->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_18, 3, 2, 1, 1);

        label_15 = new QLabel(Board);
        label_15->setObjectName("label_15");
        label_15->setFont(font1);
        label_15->setLayoutDirection(Qt::RightToLeft);
        label_15->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 153, 0)"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_15, 3, 3, 1, 1);

        pushButton_4 = new QPushButton(pageGame);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(60, 10, 121, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";\n"
"background-color:rgb(235, 217, 129);\n"
"border-radius:10px;\n"
"color:rgb(0, 0, 0)"));
        pushButton_5 = new QPushButton(pageGame);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(290, 10, 131, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";\n"
"background-color:rgb(235, 217, 129);\n"
"border-radius:10px;\n"
"color:rgb(0, 0, 0);"));
        widget = new QWidget(pageGame);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(509, 49, 311, 441));
        widget->setStyleSheet(QString::fromUtf8(""));
        label_17 = new QLabel(widget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(90, 20, 131, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Algerian")});
        font2.setPointSize(22);
        label_17->setFont(font2);
        label_17->setStyleSheet(QString::fromUtf8("background-color:#bcaea1;\n"
"border-radius:10px;\n"
"border:2px solid rgb(170, 170, 127)"));
        label_17->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(widget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(90, 230, 131, 71));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("background-color:#bcaea1;\n"
"border-radius:10px;\n"
"border:2px solid rgb(170, 170, 127)"));
        label_19->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(widget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(40, 100, 231, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(16);
        label_20->setFont(font3);
        label_20->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(widget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(40, 310, 231, 51));
        label_21->setFont(font3);
        label_21->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(pageGame);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(MyCPlusClass);
        QObject::connect(pushButton_2, SIGNAL(clicked()), MyCPlusClass, SLOT(exit()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MyCPlusClass, SLOT(playGame()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), MyCPlusClass, SLOT(newGame()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), MyCPlusClass, SLOT(reGame()));

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MyCPlusClass);
    } // setupUi

    void retranslateUi(QWidget *MyCPlusClass)
    {
        MyCPlusClass->setWindowTitle(QCoreApplication::translate("MyCPlusClass", "MyCPlus", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MyCPlusClass", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MyCPlusClass", "\350\277\233\345\205\245\346\270\270\346\210\217", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_3->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_4->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_5->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_7->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_8->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_9->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_6->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_10->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_12->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_11->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_13->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_16->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_14->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_18->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        label_15->setText(QCoreApplication::translate("MyCPlusClass", "1", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MyCPlusClass", "\346\226\260\346\270\270\346\210\217", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MyCPlusClass", "\350\277\224\345\233\236\344\270\273\351\241\265\351\235\242", nullptr));
        label_17->setText(QCoreApplication::translate("MyCPlusClass", "Score", nullptr));
        label_19->setText(QCoreApplication::translate("MyCPlusClass", "Best", nullptr));
        label_20->setText(QCoreApplication::translate("MyCPlusClass", "TextLabel", nullptr));
        label_21->setText(QCoreApplication::translate("MyCPlusClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyCPlusClass: public Ui_MyCPlusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCPLUS_H
