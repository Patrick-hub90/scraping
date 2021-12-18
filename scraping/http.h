#ifndef MONTHREAD_H
#define MONTHREAD_H

#include <QtGui>
#include <QtNetwork>
#include <QUrl>
#include <QWidget>
class MonThread : public QWidget
{
    Q_OBJECT

    public:
        MonThread(QUrl const& lien, QWidget* parent = 0);
        QPixmap imag;
        int posit;
    protected:
        void run();

    public slots:
        void readyRead();
        void finish();
        void error(QNetworkReply::NetworkError code);
    signals:
        void readRead();
        void err(QString);
    private:
        QNetworkReply *m_reply;
        QByteArray m_data;
        QUrl m_lien;

};

#endif // MONTHREAD_H
