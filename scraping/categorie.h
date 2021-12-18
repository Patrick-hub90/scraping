#ifndef CATEGORIE_H
#define CATEGORIE_H
#include "ui_categorie.h"
#include <QWidget>
#include <QPixmap>
#include <vector>
#include "image.h"
#include <QLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QMainWindow>
#include "mainwindow.h"
class Categorie : public QMainWindow,private Ui::Categorie
{
    Q_OBJECT
public:
     Categorie();
     Categorie(QPixmap const& other,QString nom,QList<QList<QString>> magasin);
    ~Categorie();
public slots:
     void m_revenir();
     void display();
signals:
     void clik();
private:
     Image *m_image;
     QList<QList<QString>> m_magasin;
     QVBoxLayout *m_layout;
     QList<QString> m_liste;
     int position;
     int nb;
};

#endif // CATEGORIE_H
