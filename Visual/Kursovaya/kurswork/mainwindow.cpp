#include "deletecategory.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPicture>
#include <QStandardItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setWindowIcon(QIcon("../Kursovaya/Files/Icons/compose_icon_125000.svg"));

    ui->SearchButton->setShortcut(QKeySequence("CTRL+F"));
    ui->SearchButton->setToolTip("Поиск товара по имени(CTRL+F)");

    ui->DeleteButton->setShortcut(QKeySequence("DELETE"));
    ui->DeleteButton->setToolTip("Удаление товара(DELETE)");

    ui->pushButton_2->setShortcut(QKeySequence("CTRL+DELETE"));
    ui->pushButton_2->setToolTip("Удаление категории товаров(CTRL+DELETE)");

    ui->AddButton->setShortcut(QKeySequence("CTRL+A"));
    ui->AddButton->setToolTip("Добавление новых товаров(CTRL+A)");

    ui->pushButton->setShortcut(QKeySequence("CTRL+BACKSPACE"));
    ui->pushButton->setToolTip("Отмена поиска(CTRL+BACKSPACE)");

    ui->HelpButton->setIcon(QIcon("../Kursovaya/Files/Icons/information_outline_icon_124942.svg"));
    ui->HelpButton->setShortcut(QKeySequence("CTRL+H"));
    ui->HelpButton->setToolTip("Открытие справки(CTRL+H)");

    this->query.exec("SELECT name from sqlite_master where type = 'table'");
    if(this->query.first())
        this->Category = this->query.value(0).toString();
    this->SQLrequest = "SELECT Name, Number, Weight, Cost, Image FROM '" + this->Category +"'";
    ui->pushButton->hide();
    DrawTable();
    UpdateCategoryList();


}

MainWindow::~MainWindow()
{
    delete ui;
}


//Вывод таблицы
void MainWindow::DrawTable(){
    int i = 0;
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;

    QStringList horizontalHeader;
    horizontalHeader.append("Название");
    horizontalHeader.append("Количество");
    horizontalHeader.append("Вес");
    horizontalHeader.append("Цена");
    horizontalHeader.append("Изображение");

    model->setHorizontalHeaderLabels(horizontalHeader);

    ui->Table->setModel(model);

    QStringList verticalHeader;

    //Осуществляем запрос

    this->query.exec(SQLrequest);

    while (this->query.next()) {
    verticalHeader.append(QString::number(i + 1));

    QString name = this->query.value(0).toString();
    QString number = this->query.value(1).toString();
    QString weight = this->query.value(2).toString();
    QString cost = this->query.value(3).toString();
    QByteArray pixmap = this->query.value(4).toByteArray();
    QPixmap pxm;
    pxm.loadFromData(pixmap);
    pxm = pxm.scaled(QSize(128, 128));

    item = new QStandardItem(name);
    model->setItem(i, 0, item);

    item = new QStandardItem(number);
    model->setItem(i, 1, item);

    item = new QStandardItem(weight);
    model->setItem(i, 2, item);

    item = new QStandardItem(cost);
    model->setItem(i, 3, item);

    QStandardItem *item = new QStandardItem();
    item->setData(QVariant(pxm), Qt::DecorationRole);
    model->setItem(i, 4, item);
    ++i;
    }

    model->setVerticalHeaderLabels(verticalHeader);
    ui->Table->resizeRowsToContents();
    ui->Table->setColumnWidth(0, 300);
    ui->Table->setColumnWidth(1, 160);
    ui->Table->setColumnWidth(2, 145);
    ui->Table->setColumnWidth(3, 140);
    ui->Table->setColumnWidth(4, 230);


}


//Вывод списка категорий
void MainWindow::UpdateCategoryList(){
    ui->CategoryList->clear();
    this->query.exec("SELECT name from sqlite_master where type = 'table'");
    while (this->query.next()) {
       QString string = this->query.value(0).toString();
       ui->CategoryList->addItem(string);
    }
    ui->CategoryList->insertSeparator(ui->CategoryList->count());
    ui->CategoryList->addItem("Добавить категорию...");
    ui->CategoryList->setCurrentText(this->Category);
    DrawTable();
}

void MainWindow::DiscardCategory(){
    this->query.exec("SELECT name from sqlite_master where type = 'table'");
    if(this->query.first()){
        this->Category = this->query.value(0).toString();
        this->SQLrequest = "SELECT Name, Number, Weight, Cost, Image FROM '" + this->Category + "'";
    }
}

void MainWindow::on_AddButton_clicked(){
    this->addform = new AddElement();
    connect(this->addform, &AddElement::DrawTable, this, &MainWindow::DrawTable);
    this->file = new QFile(":/style.css");
    this->file->open(QFile::ReadOnly);
    this->addform->setStyleSheet(file->readAll());
    this->addform->show();
}


void MainWindow::on_CategoryList_activated(const QString &arg1){   
    if(arg1 == "Добавить категорию..."){
        this->addcategory = new AddCategory();
        connect(this->addcategory, &AddCategory::UpdateCategoryList, this, &MainWindow::UpdateCategoryList);
        this->file = new QFile(":/style.css");
        this->file->open(QFile::ReadOnly);
        this->addcategory->setStyleSheet(file->readAll());
        this->addcategory->show();
    }else{
        this->Category = arg1;
        if(ui->SearchLine->text().isEmpty())
            this->SQLrequest = "SELECT Name, Number, Weight, Cost, Image FROM '" + this->Category + "'";
        else
            this->SQLrequest = "SELECT Name, Number, Weight, Cost, Image FROM '" + this->Category + "' WHERE Name  = '" + ui->SearchLine->text() + "'";

        DrawTable();
    }
}

void MainWindow::on_SearchButton_clicked(){
    if(ui->SearchLine->text().isEmpty())
        QMessageBox::warning(nullptr, "Ошибка!!!","Запрос для поиска пуст.");
    else{
        this->SQLrequest = "SELECT Name, Number, Weight, Cost, Image FROM '" + this->Category + "' WHERE Name  LIKE '" + ui->SearchLine->text() + "%'";
        ui->pushButton->show();
        DrawTable();
    }
}

void MainWindow::on_DeleteButton_clicked(){
    this->DeleteElem = new deleteelement;
    connect(this->DeleteElem, &deleteelement::DrawTable, this, &MainWindow::DrawTable);
    this->file = new QFile(":/style.css");
    this->file->open(QFile::ReadOnly);
    this->DeleteElem->setStyleSheet(file->readAll());
    this->DeleteElem->show();
}

void MainWindow::on_pushButton_clicked(){
     this->SQLrequest = "SELECT Name, Number, Weight, Cost, Image FROM '" + this->Category +"'";
     ui->SearchLine->clear();
     ui->pushButton->hide();
     DrawTable();
}

void MainWindow::on_pushButton_2_clicked(){
    this->deletecategory = new DeleteCategory;
    this->file = new QFile(":/style.css");
    this->file->open(QFile::ReadOnly);
    connect(this->deletecategory, &DeleteCategory::DiscardCategory, this, &MainWindow::DiscardCategory);
    connect(this->deletecategory, &DeleteCategory::UpdateCategoryList, this, &MainWindow::UpdateCategoryList);
    this->deletecategory->setStyleSheet(file->readAll());
    this->deletecategory->show();
}


void MainWindow::on_HelpButton_clicked(){
    help = new Help;
    help->show();
}
