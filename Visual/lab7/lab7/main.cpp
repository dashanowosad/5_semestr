#include "paint.h"
#include "snowflake.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

int main(int argc, char *argv[])
{
    int w = 800, h = 600;
    QApplication a(argc, argv);

//создали графическую сцену и ее вид
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.setFixedSize(w, h);
    view.setSceneRect(0, 0, w, h);
    view.fitInView(0,  0, w, h, Qt::KeepAspectRatio);

    //добавили стены
    scene.addRect(-105, -100, 20, h + (105*2), QPen(), QColor(30,32,61));
    scene.addRect(-105, -80, w + (105*2), 20, QPen(), QColor(30,32,61));
    scene.addRect(w+84, -100, 20, h + (105*2), QPen(), QColor(30,32,61));
    scene.addRect(-105, h+58, w + (105*2), 20, QPen(), QColor(30,32,61));

//отобразили ель
    Paint el;
    view.show();
    scene.addItem(el.GetPolygon());

//добавление изображение шариков
    QPixmap pic;
    pic.load("../Images/1.png");
    pic =  pic.scaled(QSize(40, 40));
    QGraphicsPixmapItem * shar1 = scene.addPixmap(pic);
    shar1->setPos(105,250);

    pic.load("../Images/2.png");
    pic =  pic.scaled(QSize(40, 40));
    QGraphicsPixmapItem * shar2 = scene.addPixmap(pic);
    shar2->setPos(180,315);

    pic.load("../Images/3.png");
    pic =  pic.scaled(QSize(40, 40));
    QGraphicsPixmapItem * shar3 = scene.addPixmap(pic);
    shar3->setPos(105,355);

    shar1->setFlag(QGraphicsPixmapItem::ItemIsMovable);
    shar2->setFlag(QGraphicsPixmapItem::ItemIsMovable);
    shar3->setFlag(QGraphicsPixmapItem::ItemIsMovable);

    snowflake flake(w, h, scene);
    flake.move();
    return a.exec();
}
