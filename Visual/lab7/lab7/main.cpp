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



    Paint el;
    view.show();
    scene.addItem(el.GetPolygon());
    return a.exec();
}
