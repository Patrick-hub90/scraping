#include "search.h"
#include "ui_search.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include "image.h"
#include "http.h"
#include <QTextEdit>
Search::Search(QList<QString>categories,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    m_categories = categories;
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(m_revenir()));
    Affiche(ui->lineEdit->text());
    connect(ui->lineEdit,SIGNAL(textEdited(QString)),this,SLOT(Affiche(QString)));
    Affiche(ui->lineEdit->text());
}
void Search::Affiche(QString chaine)
{
    QList<QString> liste;
    for(int i=0;i<m_categories.size();i++)
    {
        QString mot;
        mot=m_categories[i];
        if (verify(chaine,mot))
        {
            liste.append(mot);
        }
    }
    if (liste.size()==0)
    {
        QLabel *label=new QLabel;
        label->setFixedSize(500,500);
        label->setText("CATEGORIES NOT FOUND");

        QVBoxLayout* layout= new QVBoxLayout;
        layout->addWidget(label);
        QWidget *contenu=new QWidget;
        contenu->setLayout(layout);
        ui->scrollArea->setWidget(contenu);
    }
    else
    {
        m_liste=liste;
        m_layout=new QVBoxLayout;
        position =0;
        for(int i=0;i<liste.size();++i)
        {
            QPixmap pix(":/image/logo-aliexpress.jpg");
            display(pix);
        }
        QWidget *contenu=new QWidget;
        contenu->setLayout(m_layout);
        ui->scrollArea->setWidget(contenu);
    }
}
void Search::display(QPixmap pix)
{
    qDebug("hf");
    QString produit;
    Image *imageLabel = new Image;
    imageLabel->setPixmap(pix);
    imageLabel->setScaledContents(true);
    imageLabel->setFixedSize(175,175);
    QTextEdit* texte = new QTextEdit;
    texte->setText(m_liste[position]);
    imageLabel->m_nom=m_liste[position];
    texte->setReadOnly(true);
    texte->setFixedSize(576,175);
    texte->setFont(QFont("MingLiU_HKSCS-ExtB"));
    QHBoxLayout* layout= new QHBoxLayout;
    layout->addWidget(imageLabel);
    layout->addWidget(texte);
    QWidget* contenue=new QWidget;
    contenue->setLayout(layout);
    connect(imageLabel,SIGNAL(clicked(QPixmap)),this,SLOT(clike(QPixmap)));
    m_layout->addWidget(contenue);
    position++;
}
void Search::clike(QPixmap pix)
{
    Image* produit = qobject_cast<Image*>(sender());
    produit_act=produit;
    emit klic(pix);
}
void Search::Erreur(QString error)
{
QMessageBox::critical(this,"error",error);
//connect(&msgBox,SIGNAL(buttonClicked(QAbstractButton)),qApp,SLOT(exit()));
}
bool Search::verify(QString chaine1, QString chaine2)
{
    for(int i=0;i<chaine1.size();++i)
    {
        if(chaine1[i]!=chaine2[i])
            return false;
    }
    return true;
}
void Search::m_revenir()
{
  emit clik();
}
QLineEdit* Search::getLineEdit()
{
    return ui->lineEdit;
}
Search::~Search()
{
    delete ui;
}
