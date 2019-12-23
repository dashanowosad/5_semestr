#include "addelement.h"
#include "ui_addelement.h"

#include <QFileDialog>
#include <iostream>
#include <QMessageBox>

AddElement::AddElement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddElement)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon("../Kursovaya/Files/Icons/document_add_icon_124988.svg"));

    ui->AddImageButton->setShortcut(QKeySequence("CTRL+O"));
    ui->AddImageButton->setToolTip("Открытие диалога для добавления изображения(CTRL+O)");
    ui->AddButton->setShortcut(QKeySequence("CTRL+S"));
    ui->AddButton->setToolTip("Подтверждение добавления товара(CTRL+S)");
    ui->CancelButton->setShortcut(QKeySequence("ESC"));
    ui->CancelButton->setToolTip("Отмена добавления товара(ESC)");
    this->query.exec("SELECT name from sqlite_master where type = 'table'");
    if(this->query.first())
        this->category = this->query.value(0).toString();
    this->query.clear();
    UpdateCategoryList();

}

void AddElement::UpdateCategoryList(){
    ui->CategoryList->clear();
    this->query.exec("SELECT name from sqlite_master where type = 'table'");
    while (this->query.next()) {
       QString string = this->query.value(0).toString();
       ui->CategoryList->addItem(string);
    }
}

AddElement::~AddElement(){
    delete ui;
}

void AddElement::on_CategoryList_activated(const QString &arg1){
    this->category = arg1;
}

void AddElement::on_CancelButton_clicked(){
    this->close();
}

void AddElement::on_AddButton_clicked(){
    if(ui->NameLineEdit->text().isEmpty() || (ui->ImageLable->text() == "Изображение")){
         QMessageBox::warning(nullptr, "Ошибка!!!", "Вы заполнили не все поля. (либо не выбрали изображение)");
    }else{
        this->Name = ui->NameLineEdit->text();
        this->Number = ui->NumberSpinBox->value();
        this->Cost = ui->CostSpinBox->value();
        this->Weight = ui->WeightSpinBox->value();
        this->query.prepare("INSERT INTO'" + this->category + "'(Name, Number, Weight, Cost, Image) VALUES(:Name, :Number, :Weight, :Cost, :Image)");
        this->query.bindValue(":Name", this->Name);
        this->query.bindValue(":Number", this->Number);
        this->query.bindValue(":Weight", this->Weight);
        this->query.bindValue(":Cost", this->Cost);
        this->query.bindValue(":Image", this->Image);
        this->query.exec();
        QMessageBox::information(nullptr, "Успех!!!","Товар успешно добавлен.");
        emit DrawTable();
        this->close();
    }
}

void AddElement::on_AddImageButton_clicked(){  
    this->filename = QFileDialog::getOpenFileName(nullptr, "Выберете изображение", QDir::currentPath(), "*.png *.jpg *.jpeg");
    QImage image(this->filename);
    QFile file(this->filename);
        if (!file.open(QIODevice::ReadOnly)) return;
        this->Image = file.readAll();

    ui->ImageLable->setPixmap(QPixmap::fromImage(image));

}
