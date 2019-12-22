#ifndef DELETEELEMENT_H
#define DELETEELEMENT_H

#include <QMainWindow>
#include <QSqlQuery>

namespace Ui {
class deleteelement;
}

class deleteelement : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteelement(QWidget *parent = nullptr);
    ~deleteelement();



private slots:
    void on_pushButton_clicked();

private:
    Ui::deleteelement *ui;
    QSqlQuery query;
    QString Category;
    void UpdateCategoryList();
signals:
    void DrawTable();
};

#endif // DELETEELEMENT_H
