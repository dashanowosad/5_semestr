#include "deletecategory.h"
#include "ui_deletecategory.h"

#include <QMessageBox>

DeleteCategory::DeleteCategory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteCategory)
{
    ui->setupUi(this);
    ui->OkButton->setShortcut(QKeySequence("CTRL+S"));
    ui->OkButton->setToolTip("Подтверждение удаления(CTRL+S)");
    this->query.exec("SELECT name from sqlite_master where type = 'table'");
    if(this->query.first())
        Category = this->query.value(0).toString();
    this->query.clear();
    DrawCategoryList();
}

DeleteCategory::~DeleteCategory()
{
    delete ui;
}

void DeleteCategory::on_CategoryList_activated(const QString &arg1){
    this->Category = arg1;
}

void DeleteCategory::DrawCategoryList(){
    ui->CategoryList->clear();
    this->query.exec("SELECT name from sqlite_master where type = 'table'");
    while (this->query.next()) {
       QString string = this->query.value(0).toString();
       ui->CategoryList->addItem(string);
    }
}

void DeleteCategory::on_OkButton_clicked(){
    this->query.exec("DROP TABLE IF EXISTS '" + this->Category + "'");
    QMessageBox::information(nullptr, "Успешно!!!", "Категория успешно удалена.");
    emit UpdateCategoryList();
    this->close();
}
