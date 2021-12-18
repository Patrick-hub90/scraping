#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QHBoxLayout>
#include <QMainWindow>
#include <QPixmap>
#include "image.h"
#include <QStackedWidget>
#include <QVector>
#include <QMap>
#include "categorie.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    void lectur_categorie();
    bool verify(QString mot);
    ~MainWindow();
public slots:
    void display(QPixmap pix);
    void arriere();
    void lectur_produit(QPixmap image);
    void lectur_prod(QPixmap image);
    void searching(QString mot);
private:
    Ui::MainWindow *ui;
    QHBoxLayout* m_layout;
    QList<QWidget*> m_liste;
    QStackedWidget *stackWidget;
    QVector<QString> m_listeCategorie;
    QVector<QString> produit;
    QMap<QString,QList<QString>> magasin;
    int position;
    QString produit_actuel;
};

#endif // MAINWINDOW_H

