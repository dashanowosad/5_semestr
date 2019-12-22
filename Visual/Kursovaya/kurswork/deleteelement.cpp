#include "deleteelement.h"
#include "ui_deleteelement.h"

#include <QMessageBox>
#include <iostream>

deleteelement::deleteelement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deleteelement)
{
    ui->setupUi(this);
    ui->pushButton->setShortcut(QKeySequence("CTRL+S"));
    ui->pushButton->setToolTip("Подтверждение удаления(CTRL+S)");
    this->query.exec("SELECT name from sqlite_master where type = 'table'");
    if(this->query.first())
        this->Category = this->query.value(0).toString();
    this->query.clear();
    UpdateCategoryList();
}

deleteelement::~deleteelement()
{
    delete ui;
}

void deleteelement::UpdateCategoryList(){
    ui->CategoryList->clear();
    this->query.exec("SELECT name from sqlite_master where type = 'table'");
    while (this->query.next()) {
       QString string = this->query.value(0).toString();
       ui->CategoryList->addItem(string);
    }
}


void deleteelement::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty())
        QMessageBox::warning(nullptr, "Ошибка!!!", "Запрос для удаления пуст.");
    else{
        if(!this->query.exec("DELETE FROM'" + this->Category + "'"
                   "WHERE Name  = '" + ui->lineEdit->text() + "'"))
            QMessageBox::warning(nullptr, "Ошибка!!!", "Такого товара не существует.");
        QMessageBox::information(nullptr, "Успех!!!", "Товар успешно удалён.");
        emit DrawTable();
        this->close();
    }
}
