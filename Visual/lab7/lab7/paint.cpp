#include "paint.h"

void paint(QGraphicsPolygonItem *Polygon)
{

    QPolygonF p;

    p << QPointF(40,200);
    p << QPointF(120,200);
    p << QPointF(90,160);
    p << QPointF(110,160);
    p << QPointF(90,130);
    p << QPointF(100,130);
    p << QPointF(80,80);

    p << QPointF(60,130);
    p << QPointF(70,130);
    p << QPointF(50,160);
    p << QPointF(70,160);

    Polygon->setPen(QPen(QColor(42,92,3)));
    Polygon->setBrush(QBrush(QColor(42,92,3)));
    Polygon->setPolygon(p);

/*
    Polygon->setPen(QPen(Qt::yellow));
    Polygon->setBrush(QBrush(Qt::green));
    Polygon->setRect(QRectF(-30, -30, 120, 80));
*/

}
