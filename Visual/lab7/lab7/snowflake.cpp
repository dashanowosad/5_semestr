#include "snowflake.h"

snowflake::snowflake()
{

}
snowflake::snowflake(int width, int height, QGraphicsScene &scene){
    this->x = (width/2 - this->w/2);
    this->y = (height/2 - this->h/2);
    pic.load("../Images/snower.webp");
    pic =  pic.scaled(QSize(128, 128));
    this->s = scene.addPixmap(pic);
    this->s->setPos(x, y);
    this->s->setFlag(QGraphicsPixmapItem::ItemIsMovable);
}
double snowflake::getX(){
    return this->x;
}

double snowflake::getY(){
    return this->y;
}
