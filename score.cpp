#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    this->score = 0;

    //draw the text item
    setPlainText(QString("SCORE: ") + QString::number(this->score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase()
{
    this->score++;
    setPlainText(QString("SCORE: ") + QString::number(this->score));
}

int Score::getScore()
{
    return this->score;
}

