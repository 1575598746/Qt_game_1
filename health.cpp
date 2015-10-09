#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    this->health = 0;

    //draw the text item
    setPlainText(QString("HEALTH: ") + QString::number(this->health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease()
{
    this->health--;
    setPlainText(QString("HEALTH: ") + QString::number(this->health));
}

int Health::getHealth()
{
    return this->health;
}
