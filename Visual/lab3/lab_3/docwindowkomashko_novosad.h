#ifndef DOCWINDOWKOMASHKO_NOVOSAD_H
#define DOCWINDOWKOMASHKO_NOVOSAD_H

#include<QTextEdit>

class DocWindowKomashko_Novosad: public QTextEdit {
    Q_OBJECT
private:
    QString m_strFileName;
public:
    DocWindowKomashko_Novosad(QWidget* pwgt = nullptr);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotChangeColor();
};

#endif // DOCWINDOWKOMASHKO_NOVOSAD_H
