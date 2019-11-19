#include "snowflake.h"

snowflake::snowflake()
{

}
snowflake::snowflake(int width, int height, QGraphicsScene &scene){

    this->x = (width/2 - this->w/2);
    this->y = (height/2 - this->h/2);
    pic.load("../Images/snower.webp");
    pic =  pic.scaled(QSize(128, 128));
    this->scene = &scene;

    this->s = scene.addPixmap(pic);
    this->s->setPos(x, y);
}

double snowflake::getX(){
    return this->x;
}

double snowflake::getY(){
    return this->y;
}

void snowflake::setX(double X){
    this->x = X;
}
void snowflake::setY(double Y){
    this->y = Y;
}

void snowflake::update(){
    if (!scene->collidingItems(s).isEmpty())
            rightDir = !rightDir;
    if(rightDir)
        setX(this->x + 1);
    else
        setX(this->x - 1);
    y = cos(d)*30 + 60;
    d+=0.05;
    this->s->setPos(this->x, this->y);


}


void snowflake::move(){
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

}

