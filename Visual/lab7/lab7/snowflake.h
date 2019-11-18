#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class snowflake
{
public:
    snowflake();
    snowflake(int width, int height, QGraphicsScene &scene);
    double getX();
    double getY();
    void update(QGraphicsScene &scene);
private:
    double x, y;
    int w = 128, h = 128;
    QGraphicsPixmapItem* s;
    QPixmap pic;
    void draw(QGraphicsScene scene);
    void move();
};

#endif // SNOWFLAKE_H
