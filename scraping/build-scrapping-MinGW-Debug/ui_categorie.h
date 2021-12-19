/********************************************************************************
** Form generated from reading UI file 'categorie.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORIE_H
#define UI_CATEGORIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Categorie
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QTextEdit *textEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Categorie)
    {
        if (Categorie->objectName().isEmpty())
            Categorie->setObjectName(QString::fromUtf8("Categorie"));
        Categorie->resize(800, 705);
        pushButton = new QPushButton(Categorie);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 111, 23));
        label = new QLabel(Categorie);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 471, 281));
        textEdit = new QTextEdit(Categorie);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(500, 40, 281, 281));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(22);
        font.setBold(true);
        textEdit->setFont(font);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::OpenHandCursor)));
        scrollArea = new QScrollArea(Categorie);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 320, 751, 391));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MingLiU_HKSCS-ExtB")});
        font1.setPointSize(11);
        font1.setBold(false);
        scrollArea->setFont(font1);
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 749, 389));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Categorie);

        QMetaObject::connectSlotsByName(Categorie);
    } // setupUi

    void retranslateUi(QWidget *Categorie)
    {
        Categorie->setWindowTitle(QCoreApplication::translate("Categorie", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Categorie", "Revenir A l'Accueil", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Categorie: public Ui_Categorie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORIE_H
