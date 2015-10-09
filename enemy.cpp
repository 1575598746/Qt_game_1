#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <stdlib.h>
#include "game.h"

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //drew enemy
    QPixmap pixmap_0, pixmap_1, pixmap_2;
    pixmap_0.load(":/images/image/Corellian_archigraphs.ico");
    pixmap_1.load(":/images/image/DridStarFighter_archigraphs.ico");
    pixmap_2.load(":/images/image/JediStarFighter_archigraphs.ico");
    QPixmap fitpixmap_0 = pixmap_0.scaled(100,100, Qt::KeepAspectRatioByExpanding);
    QPixmap fitpixmap_1 = pixmap_1.scaled(100,100, Qt::KeepAspectRatioByExpanding);
    QPixmap fitpixmap_2 = pixmap_2.scaled(100,100, Qt::KeepAspectRatioByExpanding);

    int pixmap_random_number = rand() % 3;
    if(pixmap_random_number == 0){
        setPixmap(fitpixmap_0);
    }
    else if(pixmap_random_number == 1){
        setPixmap(fitpixmap_1);
    }
    else{
        setPixmap(fitpixmap_2);
    }

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}



void Enemy::move()
{
    this->setPos(this->x(), this->y() + 5);
    if(pos().y() - 100 > 600){
        scene()->removeItem(this);
        delete this;
        game->health->decrease();
        qDebug() << "enemy deleted" << endl;
    }

}


