#ifndef ADDELEMENT_H
#define ADDELEMENT_H

#include "addcategory.h"

#include <QMainWindow>
#include <QSqlQuery>

namespace Ui {
class AddElement;
}

class AddElement : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddElement(QWidget *parent = nullptr);
    ~AddElement();

private:
    Ui::AddElement *ui;
    QSqlQuery query;
    QString category;
    double Cost;
    double Weight;
    int Number;
    QString Name;
    QByteArray Image;
    QString filename;
    void UpdateCategoryList();

private slots:

    void on_CategoryList_activated(const QString &arg1);
    void on_CancelButton_clicked();
    void on_AddButton_clicked();
    void on_AddImageButton_clicked();
signals:
    void DrawTable();
};

#endif // ADDELEMENT_H
