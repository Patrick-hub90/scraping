#include "categorie.h"
#include "ui_categorie.h"
#include "image.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QPalette>
#include <QMessageBox>
#include "http.h"
#include "QLayout"
#include <QTextEdit>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QFont>
#include <QPushButton>
#include <time.h>
Categorie::Categorie()
{

}
Categorie::Categorie(QPixmap const& other,QString nom,QList<QList<QString>> magasin)
{
    setupUi(this);
    nb=0;
    this->setFixedSize(800,750);
    label->setScaledContents(true);
    label->setFixedSize(500,281);
    label->setPixmap(other);
    m_magasin=magasin;
    textEdit->setText(nom);
    textEdit->setReadOnly(true);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(m_revenir()));
    m_layout=new QVBoxLayout;
    position=0;
    for(int i=0;i<m_magasin.size();i++)
    {
        m_liste=m_magasin[i];
        QString filename="https:"+m_liste[1];
        MonThread *moteur=new MonThread(QUrl(filename));
        connect(moteur,SIGNAL(readRead()),this,SLOT(display()));
        moteur->posit=i;
    }
    QWidget *contenu=new QWidget;
    contenu->setLayout(m_layout);
    scrollArea->setWidget(contenu);
}
void Categorie::m_revenir()
{
  emit clik();
}
Categorie::~Categorie()
{

}
void Categorie::display()
{
    MonThread* product = qobject_cast<MonThread*>(sender());
    QList<QString> produit;
    if(!product->imag.isNull())
   {
        Image *imageLabel = new Image;
        imageLabel->setPixmap(product->imag);
        imageLabel->setScaledContents(true);
        imageLabel->setFixedSize(175,175);
        QTextEdit* texte = new QTextEdit;
        produit=m_magasin[product->posit];
        texte->setText(produit[0]+"\n\n"+produit[2]+"\n"+produit[3]+"\n"+produit[4]);
        texte->setReadOnly(true);
        texte->setFixedSize(576,175);
        texte->setFont(QFont("MingLiU_HKSCS-ExtB"));
        QHBoxLayout* layout= new QHBoxLayout;
        layout->addWidget(imageLabel);
        layout->addWidget(texte);
        QWidget* contenue=new QWidget;
        contenue->setLayout(layout);
        m_layout->addWidget(contenue);
        position++;
    }
}

