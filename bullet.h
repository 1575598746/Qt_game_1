#ifndef BULLET
#define BULLET

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>


class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem* parent = 0);


public slots:
    void move();

private:
    QPixmap pixmap;
    QPixmap fitpixmap;
};

#endif // BULLET

