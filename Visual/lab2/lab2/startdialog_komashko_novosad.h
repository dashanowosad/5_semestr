#ifndef STARTDIALOG_KOMASHKO_NOVOSAD_H
#define STARTDIALOG_KOMASHKO_NOVOSAD_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog_komashko_novosad.h"

class StartDialog_Komashko_Novosad : public QPushButton
{
    Q_OBJECT
public:
    StartDialog_Komashko_Novosad(QWidget *pwgt = 0) : QPushButton("Нажми", pwgt){
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked(){
        InputDialog_Komashko_Novosad * pInputDialog = new InputDialog_Komashko_Novosad;
        if (pInputDialog->exec() == QDialog::Accepted){
            QMessageBox::information(0,
                                     "Ваша информация ",
                                     "Имя "
                                     + pInputDialog->firstName()
                                     + "\nФамилия: "
                                     + pInputDialog->lastName()
                                     );
        }
        delete pInputDialog;
    }
};

#endif // STARTDIALOG_KOMASHKO_NOVOSAD_H
