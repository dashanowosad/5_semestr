#ifndef ADDELEMENT_H
#define ADDELEMENT_H

#include <QMainWindow>

namespace Ui {
class AddElement;
}

class AddElement : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddElement(QWidget *parent = nullptr);
    ~AddElement();

private:
    Ui::AddElement *ui;
};

#endif // ADDELEMENT_H
