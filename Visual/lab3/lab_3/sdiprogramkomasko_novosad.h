#ifndef SDIPROGRAMKOMASKO_NOVOSAD_H
#define SDIPROGRAMKOMASKO_NOVOSAD_H

#include <QMainWindow>
#include <QtWidgets>
#include "docwindowkomashko_novosad.h"


/*namespace Ui {
class SDIProgramKomasko_Novosad;
}*/

/*class SDIProgramKomasko_Novosad : public QMainWindow
{
    Q_OBJECT

public:
    explicit SDIProgramKomasko_Novosad(QWidget *parent = nullptr);
    ~SDIProgramKomasko_Novosad();

private:
    Ui::SDIProgramKomasko_Novosad *ui;
};*/

class SDIProgramKomasko_Novosad : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgramKomasko_Novosad(QWidget* pwgt = nullptr): QMainWindow(pwgt){
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        DocWindowKomashko_Novosad* pdoc = new DocWindowKomashko_Novosad;

        pmnuFile->addAction("&Open...",
                            pdoc,
                            SLOT(slotLoad()),
                            QKeySequence("CTRL+O")
                            );
        pmnuFile->addAction("&Save",
                            pdoc,
                            SLOT(slotSave()),
                            QKeySequence("CTRL+S")
                            );
        pmnuFile->addAction("&Save As...",
                            pdoc,
                            SLOT(slotSaveAs()),
                            QKeySequence("CTRL+SHIFT+S")
                            );
        pmnuFile->addAction("&Color",
                            pdoc,
                            SLOT(slotChangeColor()),
                            QKeySequence("CTRL+P")
                            );
        pmnuFile->addSeparator();
        pmnuFile->addAction("&Quit",
                            qApp,
                            SLOT(quit()),
                            QKeySequence("CTRL+Q")
                            );
        pmnuHelp->addAction("About",
                            this,
                            SLOT(slotAbout()),
                            Qt::Key_F1
                    );
        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);

        setCentralWidget(pdoc);

        connect(pdoc,
                SIGNAL(changeWindowTitle(const QSting&)),
                SLOT(slotChangeWindowTitle(const QString&))
                );
        statusBar()->showMessage("Ready", 2000);
    }
public slots:
    void slotAbout(){
        QMessageBox::about(this, "About", "Новосад Дарья и Комашко Тимур, ИП-715");
    }
    void slotChangeWindowTitle(const QString& str){
        setWindowTitle(str);
    }


};
#endif // SDIPROGRAMKOMASKO_NOVOSAD_H
