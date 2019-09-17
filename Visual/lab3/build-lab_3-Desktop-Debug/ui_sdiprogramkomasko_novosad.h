/********************************************************************************
** Form generated from reading UI file 'sdiprogramkomasko_novosad.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDIPROGRAMKOMASKO_NOVOSAD_H
#define UI_SDIPROGRAMKOMASKO_NOVOSAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SDIProgramKomasko_Novosad
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SDIProgramKomasko_Novosad)
    {
        if (SDIProgramKomasko_Novosad->objectName().isEmpty())
            SDIProgramKomasko_Novosad->setObjectName(QStringLiteral("SDIProgramKomasko_Novosad"));
        SDIProgramKomasko_Novosad->resize(400, 300);
        menuBar = new QMenuBar(SDIProgramKomasko_Novosad);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SDIProgramKomasko_Novosad->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SDIProgramKomasko_Novosad);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SDIProgramKomasko_Novosad->addToolBar(mainToolBar);
        centralWidget = new QWidget(SDIProgramKomasko_Novosad);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SDIProgramKomasko_Novosad->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SDIProgramKomasko_Novosad);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SDIProgramKomasko_Novosad->setStatusBar(statusBar);

        retranslateUi(SDIProgramKomasko_Novosad);

        QMetaObject::connectSlotsByName(SDIProgramKomasko_Novosad);
    } // setupUi

    void retranslateUi(QMainWindow *SDIProgramKomasko_Novosad)
    {
        SDIProgramKomasko_Novosad->setWindowTitle(QApplication::translate("SDIProgramKomasko_Novosad", "SDIProgramKomasko_Novosad", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SDIProgramKomasko_Novosad: public Ui_SDIProgramKomasko_Novosad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDIPROGRAMKOMASKO_NOVOSAD_H
