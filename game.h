#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "score.h"
#include "myrect.h"
#include "health.h"
#include <QObject>
#include "bullet.h"


class Game : public QGraphicsView
{

public:
    Game(QGraphicsView *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    QGraphicsScene *Scene;
    MyRect *player;
    Score *score;
    Health *health;
    //Bullet bullet;
    //Bullet_1 *createdBullet;
private:
    int indexOfBullet = 1;

//    void spawn();
//    void createEnemy();
};



#endif // GAME_H
