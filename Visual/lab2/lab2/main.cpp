#include "startdialog_komashko_novosad.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog_Komashko_Novosad startDialog;
    startDialog.show();
    return a.exec();
}
