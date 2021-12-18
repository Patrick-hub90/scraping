#ifndef SEARCH_H
#define SEARCH_H
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include "mainwindow.h"
namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QList<QString>categories,QWidget *parent = nullptr);
    ~Search();
   bool verify(QString chaine1,QString chaine2);
   void lectur_produit(QPixmap image);
   Image *produit_act;
   QLineEdit* getLineEdit();
public slots:
    void m_revenir();
    void Affiche(QString chaine);
    void display(QPixmap pix);
    void Erreur(QString error);
    void clike(QPixmap pix);
signals:
     void clik();
     void klic(QPixmap);
private:
    Ui::Search *ui;
    QList<QString> m_categories;
     QVBoxLayout* m_layout;
     QList<QString> m_liste;
     MainWindow *m_fenetre;
     int position;
};

#endif // SEARCH_H
