#include "help.h"
#include "ui_help.h"

#include <QIcon>

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../Kursovaya/Files/Icons/information_outline_icon_124942.svg"));
    this->file = new QFile(":/style.css");
        this->file->open(QFile::ReadOnly);
        ui->textBrowser->setStyleSheet(file->readAll());
    ui->textBrowser->setSource(QUrl("../Kursovaya/Files/Help/Main.html"));

}

Help::~Help()
{
    delete ui;
}
