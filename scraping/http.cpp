#include "http.h"
#include <QWidget>

MonThread::MonThread(QUrl const& lien,QWidget* parent) : QWidget(parent),m_lien(lien)
{
    MonThread::run();
}

void MonThread::run()
{
    m_data=QByteArray();
    QNetworkRequest request = QNetworkRequest(m_lien);
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    m_reply = manager->get(request);
    connect(m_reply, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(m_reply, SIGNAL(finished()), this, SLOT(finish()));
    connect(m_reply,SIGNAL(errorOccurred(QNetworkReply::NetworkError)),this,SLOT(error(QNetworkReply::NetworkError)));
}
void MonThread::readyRead()
{
    bool ErrorFound=true;
    if(ErrorFound==false)
       m_data.append(m_reply->readAll());
}
void MonThread::error(QNetworkReply::NetworkError code)
{
  QString er=m_reply->errorString();
  emit err(er);
}
void MonThread::finish()
{
    m_data.append(m_reply->readAll());
    QPixmap image;
    image.loadFromData(m_data);
    imag=image;
    emit readRead();
    m_reply->deleteLater();

}
