#ifndef PAINT_H
#define PAINT_H

#include <QPolygonF>
#include <QGraphicsPolygonItem>
#include <QPen>

class Paint
{
public:
    Paint();
    QGraphicsPolygonItem* GetPolygon();
private:
    QGraphicsPolygonItem* Polygon;
    QPolygonF p;
    QPolygonF p1;
};

#endif // PAINT_H
