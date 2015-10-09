#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>
#include <typeinfo>
#include <stdlib.h>
//#include "bullet_1.h"

extern Game *game;

Bullet::Bullet(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    pixmap.load(":/images/image/24.png");
    fitpixmap = pixmap.scaled(10,10, Qt::KeepAspectRatioByExpanding);
    setPixmap(fitpixmap);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer->start(50);
}



//void Bullet::changeBullet()
//{
//    if(iterate_number == 3){
//        iterate_number = 0;
//    }

//    if(iterate_number == 0){
//        pixmap.load(":/images/image/24.png");
//        fitpixmap = pixmap.scaled(10,10, Qt::KeepAspectRatioByExpanding);
//        ++iterate_number;
//    }
//    else if(iterate_number == 1){
//        pixmap.load(":/images/image/12.png");
//        fitpixmap = pixmap.scaled(20,20, Qt::KeepAspectRatioByExpanding);
//        ++iterate_number;
//    }
//    else{
//        pixmap.load(":/images/image/23.png");
//        fitpixmap = pixmap.scaled(20,20, Qt::KeepAspectRatioByExpanding);
//        ++iterate_number;
//    }


//}



void Bullet::move()
{
    //if bullet hits enemy, delete both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(QList<QGraphicsItem *>::iterator it = colliding_items.begin();
        it != colliding_items.end(); ++it){
        if(typeid(*(*it)) == typeid(Enemy)){
            //increase the score
            game->score->increase();
            //remove both
            scene()->removeItem(*it);
            scene()->removeItem(this);
            delete *it;
            *it = NULL;
            delete this;
            //this = NULL;
            return;
        }
    }

    this->setPos(this->x(), this->y() - 10);

    if(pos().y() + 10 < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted" << endl;
    }
}

