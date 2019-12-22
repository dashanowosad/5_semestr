#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include "addelement.h"
#include "addcategory.h"
#include "deleteelement.h"

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "deletecategory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void test();

private:
    Ui::MainWindow *ui;
    AddElement *addform;
    AddCategory *addcategory;
    deleteelement *DeleteElem;
    DeleteCategory *deletecategory;
    QString Category;
    QSqlQuery query;
    QString SQLrequest;
    QFile *file;


private slots:
    void UpdateCategoryList();
    void DrawTable();
    void on_AddButton_clicked();
    void on_CategoryList_activated(const QString &arg1);
    void on_SearchButton_clicked();
    void on_DeleteButton_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
