/********************************************************************************
** Form generated from reading UI file 'auth.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_H
#define UI_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_auth
{
public:
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *auth)
    {
        if (auth->objectName().isEmpty())
            auth->setObjectName(QStringLiteral("auth"));
        auth->resize(1212, 663);
        label = new QLabel(auth);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 0, 951, 611));
        label->setPixmap(QPixmap(QString::fromUtf8("../4233823-bolivia.jpg")));
        textEdit = new QTextEdit(auth);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(250, 600, 711, 61));
        QFont font;
        font.setFamily(QStringLiteral("Open Sans"));
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        textEdit->setFont(font);
        textEdit->raise();
        label->raise();

        retranslateUi(auth);

        QMetaObject::connectSlotsByName(auth);
    } // setupUi

    void retranslateUi(QDialog *auth)
    {
        auth->setWindowTitle(QApplication::translate("auth", "Dialog", Q_NULLPTR));
        label->setText(QString());
        textEdit->setHtml(QApplication::translate("auth", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:18pt; font-weight:600; font-style:italic;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans'; font-size:24pt;\">\320\230\320\237-715 \320\232\320\276\320\274\320\260\321\210\320\272\320\276 \320\242\320\270\320\274\321\203\321\200 \320\270 \320\235\320\276\320\262\320\276\321\201\320\260\320\264 \320\224\320\260\321\200\321\214\321\217</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class auth: public Ui_auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_H
