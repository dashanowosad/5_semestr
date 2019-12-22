#include "mainwindow.h"
#include <QApplication>
#include <QColor>
#include <QFile>
#include <QMessageBox>
#include <QSplashScreen>
#include <QTime>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "addelement.h"
#include <iostream>
#include <string>

void loadModules(QSplashScreen* psplash){
    QTime time;
    time.start();
    size_t i = 0;
    while(i < 100){
        if(time.elapsed() > 40){
            time.start();
            ++i;
        }
        psplash->showMessage("Loading modules: "
                             + QString::number(i) + "%",
                             Qt::AlignCenter|Qt::AlignCenter,
                             Qt::white
                    );
        qApp->processEvents();
    }
}



int main(int argc, char *argv[])
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../Kursovaya/Files/DataBase/test.db");

    if(!db.open()){
        std::cerr << "Database open fail";
        return 0;
    }
    QFile file(":/style.css");
    file.open(QFile::ReadOnly);

    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap("../Kursovaya/Files/Images/SplashScreen.png"));
    splash.show();
    MainWindow w;
    loadModules(&splash);
    splash.finish(&w);
    w.setStyleSheet(file.readAll());
    w.show();

    return a.exec();
}
