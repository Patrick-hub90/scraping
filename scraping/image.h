#ifndef IMAGE_H
#define IMAGE_H
#include <QLabel>
#include <QPixmap>
#include <QUrl>
#include <QString>
#include <QWidget>
#include <QEvent>
class Image:public QLabel
{
    Q_OBJECT
public:
    Image()
    {

    }
    Image(Image const& other,QLabel* parent=nullptr):QLabel(parent)
    {
        this->setText(other.text());
        this->setPixmap(other.pixmap());
        m_nom=other.m_nom;
        posit=other.posit;
    }
    ~Image()
    {

    }
    void mouseDoubleClickEvent(QMouseEvent *e)
      {
        emit clicked(this->pixmap());
        QLabel::mouseDoubleClickEvent(e);
      }
    int posit;
    QString m_nom;
  signals:
    void clicked(QPixmap);
protected:

};


#endif // IMAGE_H
