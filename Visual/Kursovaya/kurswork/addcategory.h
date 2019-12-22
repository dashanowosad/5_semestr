#ifndef ADDCATEGORY_H
#define ADDCATEGORY_H

#include <QMainWindow>
#include <QSqlQuery>

namespace Ui {
class AddCategory;
}

class AddCategory : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddCategory(QWidget *parent = nullptr);
    ~AddCategory();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddCategory *ui;
    QSqlQuery query;
signals:
    void UpdateCategoryList();
};

#endif // ADDCATEGORY_H
