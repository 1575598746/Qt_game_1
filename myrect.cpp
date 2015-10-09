#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>


MyRect::MyRect(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //drew player

    pixmap_0.load(":/images/image/MilleniumFalcon_archigraphs.ico");
    pixmap_1.load(":/images/image/NabooStarFighter_archigraphs.ico");
    pixmap_2.load(":/images/image/RepublicCruiser_archigraphs.ico");
    fitpixmap_0 = pixmap_0.scaled(100,100, Qt::KeepAspectRatioByExpanding);
    fitpixmap_1 = pixmap_1.scaled(100,100, Qt::KeepAspectRatioByExpanding);
    fitpixmap_2 = pixmap_2.scaled(100,100, Qt::KeepAspectRatioByExpanding);
    this->setPixmap(fitpixmap_2);
}

//void MyRect::keyPressEvent(QKeyEvent *event)
//{
//    if(event->key() == Qt::Key_Left){
//        if(pos().x() > 0){
//            this->setPos(this->x() - 10, this->y());
//        }

//    }
//    else if(event->key() == Qt::Key_Right){
//        if(pos().x() + 100 < 800){
//            this->setPos(this->x() + 10, this->y());
//        }

//    }
//    else if(event->key() == Qt::Key_Space){
//        Bullet *bullet = new Bullet();
//        bullet->setPos(this->x() + 45, this->y());
//        scene()->addItem(bullet);
//    }
//    else if(event->key() == Qt::Key_Enter){

//    }

//}

void MyRect::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
