/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *mainpage;
    QWidget *topBg;
    QLabel *label;
    QLabel *topLabel;
    QLabel *label_4;
    QPushButton *renew;
    QScrollArea *topScrollArea;
    QWidget *topScrollAreaWidgetContents;
    QWidget *btmBg;
    QLabel *btmLabel;
    QLabel *label_3;
    QScrollArea *btmScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *midBg;
    QLabel *midLabel;
    QLabel *label_2;
    QScrollArea *midScrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *articlepage;
    QWidget *topWidget;
    QPushButton *backButton_5;
    QPushButton *likeButton_5;
    QWidget *btmWidget;
    QLabel *articlename;
    QTextEdit *contentView;
    QLabel *articleImg;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(680, 780);
        Widget->setCursor(QCursor(Qt::ArrowCursor));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 680, 780));
        mainpage = new QWidget();
        mainpage->setObjectName(QStringLiteral("mainpage"));
        topBg = new QWidget(mainpage);
        topBg->setObjectName(QStringLiteral("topBg"));
        topBg->setGeometry(QRect(0, 0, 680, 300));
        label = new QLabel(topBg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(145, 40, 100, 2));
        label->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 0.4)\n"
""));
        topLabel = new QLabel(topBg);
        topLabel->setObjectName(QStringLiteral("topLabel"));
        topLabel->setGeometry(QRect(75, 25, 71, 31));
        topLabel->setStyleSheet(QString::fromUtf8("font: 24pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(topBg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 40, 15, 2));
        label_4->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 0.4)\n"
""));
        renew = new QPushButton(topBg);
        renew->setObjectName(QStringLiteral("renew"));
        renew->setGeometry(QRect(580, 20, 34, 34));
        topScrollArea = new QScrollArea(topBg);
        topScrollArea->setObjectName(QStringLiteral("topScrollArea"));
        topScrollArea->setGeometry(QRect(50, 80, 580, 200));
        topScrollArea->setMinimumSize(QSize(580, 170));
        topScrollArea->setWidgetResizable(true);
        topScrollAreaWidgetContents = new QWidget();
        topScrollAreaWidgetContents->setObjectName(QStringLiteral("topScrollAreaWidgetContents"));
        topScrollAreaWidgetContents->setGeometry(QRect(0, 0, 578, 198));
        topScrollArea->setWidget(topScrollAreaWidgetContents);
        topLabel->raise();
        label_4->raise();
        label->raise();
        renew->raise();
        topScrollArea->raise();
        btmBg = new QWidget(mainpage);
        btmBg->setObjectName(QStringLiteral("btmBg"));
        btmBg->setGeometry(QRect(0, 540, 681, 241));
        btmLabel = new QLabel(btmBg);
        btmLabel->setObjectName(QStringLiteral("btmLabel"));
        btmLabel->setGeometry(QRect(70, 10, 181, 31));
        btmLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(btmBg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 0, 581, 2));
        label_3->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0.8)\n"
""));
        btmScrollArea = new QScrollArea(btmBg);
        btmScrollArea->setObjectName(QStringLiteral("btmScrollArea"));
        btmScrollArea->setGeometry(QRect(50, 50, 580, 170));
        btmScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 578, 168));
        btmScrollArea->setWidget(scrollAreaWidgetContents_2);
        midBg = new QWidget(mainpage);
        midBg->setObjectName(QStringLiteral("midBg"));
        midBg->setGeometry(QRect(0, 300, 680, 240));
        midLabel = new QLabel(midBg);
        midLabel->setObjectName(QStringLiteral("midLabel"));
        midLabel->setGeometry(QRect(70, 10, 181, 31));
        midLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_2 = new QLabel(midBg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 0, 581, 2));
        label_2->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0.8)\n"
""));
        midScrollArea = new QScrollArea(midBg);
        midScrollArea->setObjectName(QStringLiteral("midScrollArea"));
        midScrollArea->setGeometry(QRect(50, 50, 580, 170));
        midScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 578, 168));
        midScrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(mainpage);
        articlepage = new QWidget();
        articlepage->setObjectName(QStringLiteral("articlepage"));
        topWidget = new QWidget(articlepage);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setGeometry(QRect(0, 0, 680, 61));
        backButton_5 = new QPushButton(topWidget);
        backButton_5->setObjectName(QStringLiteral("backButton_5"));
        backButton_5->setGeometry(QRect(30, 10, 40, 40));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        backButton_5->setFont(font);
        likeButton_5 = new QPushButton(topWidget);
        likeButton_5->setObjectName(QStringLiteral("likeButton_5"));
        likeButton_5->setGeometry(QRect(600, 10, 40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/xin.png"), QSize(), QIcon::Normal, QIcon::Off);
        likeButton_5->setIcon(icon);
        likeButton_5->setIconSize(QSize(30, 30));
        btmWidget = new QWidget(articlepage);
        btmWidget->setObjectName(QStringLiteral("btmWidget"));
        btmWidget->setGeometry(QRect(0, 60, 681, 721));
        articlename = new QLabel(articlepage);
        articlename->setObjectName(QStringLiteral("articlename"));
        articlename->setGeometry(QRect(130, 70, 431, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\265\252\346\274\253\351\233\205\345\234\206"));
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        articlename->setFont(font1);
        contentView = new QTextEdit(articlepage);
        contentView->setObjectName(QStringLiteral("contentView"));
        contentView->setGeometry(QRect(110, 380, 471, 371));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(10);
        contentView->setFont(font2);
        articleImg = new QLabel(articlepage);
        articleImg->setObjectName(QStringLiteral("articleImg"));
        articleImg->setGeometry(QRect(170, 130, 350, 233));
        stackedWidget->addWidget(articlepage);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "LookBoard", nullptr));
        label->setText(QString());
        topLabel->setText(QApplication::translate("Widget", "\347\234\213\346\235\277", nullptr));
        label_4->setText(QString());
        renew->setText(QString());
        btmLabel->setText(QApplication::translate("Widget", "\345\226\234\346\254\242\347\232\204\346\226\207\347\253\240", nullptr));
        label_3->setText(QString());
        midLabel->setText(QApplication::translate("Widget", "\346\234\200\350\277\221\351\230\205\350\257\273", nullptr));
        label_2->setText(QString());
        backButton_5->setText(QApplication::translate("Widget", "<", nullptr));
        likeButton_5->setText(QString());
        articlename->setText(QString());
        contentView->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\271\274\345\234\206'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        articleImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
