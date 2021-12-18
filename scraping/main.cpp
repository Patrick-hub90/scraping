#include "mainwindow.h"
#include <QProcess>
#include <QApplication>
#include <QStringList>
#include <QWidget>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
