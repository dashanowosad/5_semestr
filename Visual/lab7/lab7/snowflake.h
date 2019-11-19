
#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMainWindow>
#include <cmath>
class snowflake : QMainWindow
{
    Q_OBJECT

public:
    snowflake();
    snowflake(int width, int height, QGraphicsScene &scene);
    double getX();
    double getY();
    void setX(double X);
    void setY(double Y);
    void move();
    virtual ~snowflake(){}
public slots:
    void update();
private:
    double d = 0;
    QGraphicsScene *scene;
    bool rightDir = true;
    bool UpDIr = true;
    double x, y;
    int w = 128, h = 128;
    QTimer *timer;
    QGraphicsPixmapItem* s;
    QPixmap pic;


};

#endif // SNOWFLAKE_H
