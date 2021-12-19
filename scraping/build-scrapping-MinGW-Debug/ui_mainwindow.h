/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLineEdit *lineEdit;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 705);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(40, 130, 741, 251));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        scrollArea->setFont(font);
        scrollArea->setMouseTracking(true);
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 739, 249));
        scrollArea->setWidget(scrollAreaWidgetContents);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 80, 621, 41));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius: 20%;"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 0, 281, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe Script")});
        font1.setPointSize(34);
        font1.setBold(false);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(238, 145, 14);"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 390, 761, 251));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Mongolian Baiti")});
        font2.setPointSize(14);
        textEdit->setFont(font2);
        textEdit->setStyleSheet(QString::fromUtf8("border-radius: 30%;\n"
"background-color: rgb(255, 73, 41);\n"
""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 50, 361, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("MingLiU_HKSCS-ExtB")});
        font3.setPointSize(12);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "  Rechercher.......", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "AliExpress", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Mongolian Baiti'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">AliExpress est un g\303\251ant du commerce \303\251lectronique B2B bas\303\251 en Chine. Techniquement, il fonctionne de la m\303\252me mani\303"
                        "\250re que d'autres homologues pr\303\251\303\251minents comme Amazon ou sa soci\303\251t\303\251 m\303\250re, Alibaba. Le groupe de vente au d\303\251tail pr\303\251sente des produits de divers fournisseurs \303\240 travers le monde et se classe parmi les meilleures marques de premier ordre au monde.Dans cet esprit, vous pouvez avoir un aper\303\247u de l'origine exacte du buzz AliExpress. Ces derniers temps, les commer\303\247ants ont d\303\273 faire face aux tendances d'achat grand public. Et voici pourquoi. Les consommateurs adoptent de plus en plus la possibilit\303\251 d'acheter des produits en ligne. Ici, sur AliExpress, vous trouverez \303\251galement des articles \303\240 des prix bon march\303\251 et des plans d'exp\303\251dition flexibles.</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Acheter Malin ! Vivez-Mieux!! ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
