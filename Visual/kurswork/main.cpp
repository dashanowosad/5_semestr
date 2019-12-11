#include "mainwindow.h"
#include <QApplication>
#include "addelement.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    AddElement test;
    test.show();
//    w.show();

    return a.exec();
}
