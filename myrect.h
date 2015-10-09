#ifndef MYRECT
#define MYRECT

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class MyRect : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    MyRect(QGraphicsItem *parent = 0);
    //void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();
private:
    QPixmap pixmap_0, pixmap_1, pixmap_2;
    QPixmap fitpixmap_0, fitpixmap_1, fitpixmap_2;
};

#endif // MYRECT

