#ifndef DELETECATEGORY_H
#define DELETECATEGORY_H

#include <QMainWindow>
#include <QSqlQuery>

namespace Ui {
class DeleteCategory;
}

class DeleteCategory : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteCategory(QWidget *parent = nullptr);
    ~DeleteCategory();

private slots:
    void on_CategoryList_activated(const QString &arg1);

    void on_OkButton_clicked();

private:
    Ui::DeleteCategory *ui;
    QSqlQuery query;
    QString Category;
    void DrawCategoryList();
signals:
    void UpdateCategoryList();
};

#endif // DELETECATEGORY_H
