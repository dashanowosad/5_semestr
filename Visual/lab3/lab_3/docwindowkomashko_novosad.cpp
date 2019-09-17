#include "docwindowkomashko_novosad.h"
#include <QFileDialog>
#include <QTextStream>
#include <QColorDialog>
#include <QDebug>
#include <QMessageBox>

DocWindowKomashko_Novosad::DocWindowKomashko_Novosad(QWidget* pwgt): QTextEdit(pwgt){


}

void DocWindowKomashko_Novosad::slotLoad(){
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty()){
        return;
    }

    QFile file(str);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();


        m_strFileName = str;
        emit changeWindowTitle(m_strFileName);
    }
}

void DocWindowKomashko_Novosad::slotSaveAs() {
    QString str = QFileDialog::getSaveFileName(nullptr, m_strFileName);
    if (!str.isEmpty()){
        m_strFileName = str;
        slotSave();
    }
}

void DocWindowKomashko_Novosad::slotSave() {
    if(m_strFileName.isEmpty()){
        slotSaveAs();
        return;
    }

    QFile file(m_strFileName);

    if(file.open(QIODevice::WriteOnly)){
        QTextStream(&file) << toPlainText();
        file.close();
        emit changeWindowTitle(m_strFileName);
        QMessageBox::information(nullptr, "Information", "Save Complite");
    }
}

void DocWindowKomashko_Novosad::slotChangeColor(){
    QColor color = QColorDialog::getColor(Qt::yellow, this );
        if( color.isValid()){
          setTextColor(color.name());
         // qDebug() << "Color Choosen : " << color.name();
        }
}
