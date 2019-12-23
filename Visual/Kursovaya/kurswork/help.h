#ifndef HELP_H
#define HELP_H

#include <QFile>
#include <QWidget>

namespace Ui {
class Help;
}

class Help : public QWidget
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();

private:
    Ui::Help *ui;
    QFile *file;
};

#endif // HELP_H
