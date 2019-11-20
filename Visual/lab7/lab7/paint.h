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
    QGraphicsRectItem* GetRect();
private:
    QGraphicsPolygonItem* Polygon;
    QGraphicsRectItem* pRectItem;
    QPolygonF p;
};

#endif // PAINT_H
