#include "addcategory.h"
#include "ui_addcategory.h"
#include <iostream>
#include <QMessageBox>

AddCategory::AddCategory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddCategory)
{

    ui->setupUi(this);

    this->setWindowIcon(QIcon("../Kursovaya/Files/Icons/document_add_icon_124988.svg"));

    ui->pushButton->setShortcut(QKeySequence("CTRL+S"));
    ui->pushButton->setToolTip("Подтверждение добавления категории(CTRL+S)");
}

AddCategory::~AddCategory()
{
    delete ui;
}

void AddCategory::on_pushButton_clicked(){
    if(ui->lineEdit->text().isEmpty() == 1){
         QMessageBox::warning(nullptr ,"Ошибка!!!", "Вы не заполнили поле.");
    }else{
        this->query.exec("CREATE TABLE `"+
                         ui->lineEdit->text()+
                         "` ("
                         "  `Name`	TEXT,"
                         "  `Cost`	REAL,"
                         "  `Weight`	REAL,"
                         " `Number`	INTEGER,"
                         "`Image`	BLOB"
                         " );");
        QMessageBox::information(nullptr, "Успех!!!","Категория успешно добавлена.");
        emit UpdateCategoryList();
        this->~AddCategory();
    }
}
