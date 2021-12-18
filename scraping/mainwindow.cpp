#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "http.h"
#include "image.h"
#include <QThread>
#include <QProcess>
#include "categorie.h"
#include "search.h"
#include <QPalette>
#include <QFile>
#include <QProcess>
#include <QMessageBox>
#include <QLabel>
#include <QFont>
#include <QTextStream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      qDebug("hel");
      stackWidget=new QStackedWidget;
      ui->setupUi(this);
      connect(ui->lineEdit,SIGNAL(textEdited(QString)),this,SLOT(searching(QString)));
      produit_actuel = "";
      this->setMaximumSize(800,750);
      stackWidget->addWidget(this->centralWidget());
      stackWidget->setCurrentWidget(this->centralWidget());
      setCentralWidget(stackWidget);
      m_layout=new QHBoxLayout;
      QWidget *contenu=new QWidget;
      QProcess process;
      QString program="C:/Users/ghost/AppData/Local/Programs/Python/Python310/python.exe";
      QStringList argument;
      argument <<"C:/Users/ghost/Documents/scrap/scrapping/freepik.py";
      process.start(program,argument);
      process.waitForFinished();
      lectur_categorie();
      position = 0;
      for(int i=0;i<m_listeCategorie.size();++i)
      {       
         QPixmap pix(":/image/logo-aliexpress.jpg");
         display(pix);
      }
      contenu->setLayout(m_layout);
      ui->scrollArea->setWidget(contenu);
      ui->textEdit->setReadOnly(true);
 }
void MainWindow::lectur_categorie()
{
    QString filename(":/produit/Info_Genrale.txt");
    QFile fichier(filename);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream texte(&fichier);
    texte.setEncoding(QStringConverter::System);
    QString line;
    while(texte.readLineInto(&line))
    {
        m_listeCategorie.push_back(line);
    }
}
void MainWindow::lectur_produit(QPixmap image)
{
    Image* produit = qobject_cast<Image*>(sender());
    QString nom=m_listeCategorie[produit->posit];
    QFile fichier(":/produit/"+nom+".txt");
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream texte(&fichier);
    texte.setEncoding(QStringConverter::System);
    QString line;
    QList<QList<QString>>liste;
    while(texte.readLineInto(&line))
    {
        QList<QString> Produit;
        QString mot;
        if(line !="######################")
        {
            Produit.append(line);
        }
        while ((mot =texte.readLine(0)) != "######################")
        {
            Produit.append(mot);
        }
        liste.append(Produit);
    }
    Categorie *page_produit=new Categorie(image,m_listeCategorie[produit->posit],liste);
    stackWidget->addWidget(page_produit);
    stackWidget->setCurrentWidget(page_produit);
    connect(page_produit,SIGNAL(clik()),this,SLOT(arriere()));
}
void MainWindow::lectur_prod(QPixmap image)
{
    Search* produit = qobject_cast<Search*>(sender());
    Image* im=produit->produit_act;
    QString nom=im->m_nom;
    QFile fichier(":/produit/"+nom+".txt");
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream texte(&fichier);
    texte.setEncoding(QStringConverter::System);
    QString line;
    QList<QList<QString>>liste;
    while(texte.readLineInto(&line))
    {
        QList<QString> Produit;
        QString mot;
        if(line !="######################")
        {
            Produit.append(line);
        }
        while ((mot =texte.readLine(0)) != "######################")
        {
            Produit.append(mot);
        }
        liste.append(Produit);
    }
    Categorie *page_produit=new Categorie(image,im->m_nom,liste);
    stackWidget->addWidget(page_produit);
    stackWidget->setCurrentWidget(page_produit);
    connect(page_produit,SIGNAL(clik()),this,SLOT(arriere()));
}
bool MainWindow::verify(QString mot)
{
    for(int i=0;i < m_listeCategorie.size();i++)
    {
        if(mot == m_listeCategorie[i])
            return true;
    }
    return false;
}
 void MainWindow::display(QPixmap pix)
{
        Image *imageLabel = new Image;
        imageLabel->setScaledContents(true);
        imageLabel->setFixedSize(150,150);
        imageLabel->setPixmap(pix);
        imageLabel->posit=position;
        QTextEdit* texte=new QTextEdit;
        texte->setFixedSize(150,75);
        texte->setText( m_listeCategorie[position]);
        texte->setFont(QFont("MingLiU_HKSCS-ExtB"));
        texte->setReadOnly(true);
        QVBoxLayout *layout=new QVBoxLayout;
        layout->addWidget(imageLabel);
        layout->addWidget(texte);
        QWidget *contenu=new QWidget;
        contenu->setLayout(layout);
        m_liste.append(contenu);
        produit_actuel= m_listeCategorie[position];
        connect(imageLabel,SIGNAL(clicked(QPixmap)),this,SLOT(lectur_produit(QPixmap)));
        m_layout->addWidget(contenu);
        position++;
}

void MainWindow::searching(QString mot)
{
    Search* fenetre=new Search(m_listeCategorie);
    ui->lineEdit->setText("Rechercher....");
    fenetre->getLineEdit()->setText(mot);
    stackWidget->addWidget(fenetre);
    stackWidget->setCurrentWidget(fenetre);
    connect(fenetre,SIGNAL(clik()),this,SLOT(arriere()));
    connect(fenetre,SIGNAL(klic(QPixmap)),this,SLOT(lectur_prod(QPixmap)));
}
void MainWindow::arriere()
{
    stackWidget->setCurrentIndex(0);
}
MainWindow::~MainWindow()
{
    delete ui;
}
