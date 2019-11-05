#include "paint.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//создали графическую сцену и ее вид
    QGraphicsScene scene(QRectF(-100,-100,500,500));
    QGraphicsView view(&scene);

//рисуем елочку (через полигон)
    QGraphicsPolygonItem *Polygon = new QGraphicsPolygonItem();
    paint(Polygon);

    view.show();

    scene.addItem(Polygon);
    return a.exec();
}
