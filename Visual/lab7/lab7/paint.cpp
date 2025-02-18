#include "paint.h"
Paint::Paint() {
    Polygon = new QGraphicsPolygonItem();
    p << QPointF(80,400);
    p << QPointF(240,400);
    p << QPointF(180,320);
    p << QPointF(220,320);
    p << QPointF(180,260);
    p << QPointF(200,260);
    p << QPointF(160,160);

    p << QPointF(120,260);
    p << QPointF(140,260);
    p << QPointF(100,320);
    p << QPointF(140,320);

    this->pRectItem = new QGraphicsRectItem();
    this->pRectItem->setPen(QPen(QColor(89,53,31)));
    this->pRectItem->setBrush(QBrush(QColor(89,53,31)));
    this->pRectItem->setRect(QRectF(145, 400, 30, 50));
    this->pRectItem->setFlags(QGraphicsItem::ItemIsMovable);


    Polygon->setPen(QPen(QColor(42,92,3)));
    Polygon->setBrush(QBrush(QColor(42,92,3)));
    Polygon->setPolygon(p);
    Polygon->setFlags(QGraphicsItem::ItemIsMovable);
}

QGraphicsPolygonItem* Paint::GetPolygon(){
    return this->Polygon;
}

QGraphicsRectItem* Paint::GetRect(){
    return this->pRectItem;
}
