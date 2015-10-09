#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include "game.h"
#include <QGraphicsView>
#include <QTimer>

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();


    return a.exec();
}
