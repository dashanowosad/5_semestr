#ifndef INPUTDIALOG_KOMASHKO_NOVOSAD_H
#define INPUTDIALOG_KOMASHKO_NOVOSAD_H

#include <QDialog>
#include <QLineEdit>

class QLineEdit;

class InputDialog_Komashko_Novosad: public QDialog
{
    Q_OBJECT
private:
    QLineEdit * m_ptxtFirstName;
    QLineEdit * m_ptxtLastName;
public:
    InputDialog_Komashko_Novosad(QWidget * pwgt = 0);

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_KOMASHKO_NOVOSAD_H
