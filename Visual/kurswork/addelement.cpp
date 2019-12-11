#include "addelement.h"
#include "ui_addelement.h"

AddElement::AddElement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddElement)
{
    ui->setupUi(this);

}

AddElement::~AddElement()
{
    delete ui;
}
