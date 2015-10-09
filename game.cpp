#include "game.h"
#include "enemy.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QDebug>
#include <QBrush>

Game::Game(QGraphicsView *parent): QGraphicsView(parent)
{
    Scene = new QGraphicsScene();

    player = new MyRect();

    setBackgroundBrush(QBrush(QImage(":/images/image/apic11496.jpg")));

    Scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //QGraphicsView *view = new QGraphicsView(Scene);
    this->setScene(Scene);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->show();

    this->setFixedSize(800, 600);
    Scene->setSceneRect(0, 0, 800, 600);

    player->setPos(this->width()/2, this->height() - player->pixmap().height());

    score = new Score();
    score->setPos(0, 0);
    Scene->addItem(score);

    health = new Health();
    health->setPos(0, 0 + 25);
    Scene->addItem(health);

    //spawn enemies
    QTimer *timer = new QTimer();

    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));


    timer->start(2000);
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(player->pos().x() > 0){
            player->setPos(player->x() - 10, player->y());
        }

    }
    else if(event->key() == Qt::Key_Right){
        if(player->pos().x() + 100 < 800){
            player->setPos(player->x() + 10, player->y());
        }

    }
    else if(event->key() == Qt::Key_Space){
        Bullet* createdBullet = new Bullet;
        createdBullet->setPos(player->x() + 45, player->y());
        scene()->addItem(createdBullet);
    }
//    else if(event->key() == Qt::Key_Enter){
//        //Bullet有不同的子类
//        if(this->indexOfBullet == 3){
//            this->indexOfBullet = 1;
//        }
//        else{
//            this->indexOfBullet++;
//        }
//    }

}



//void Game::spawn()
//{
//    Enemy *enemy = new Enemy();
//    Scene->addItem(enemy);
//    qDebug() << "enemy created" << endl;
//}

//void Game::createEnemy()
//{
//    Enemy *enemy = new Enemy();
//    Scene->addItem(enemy);
//}


