#ifndef CHECKFILES1_H
#define CHECKFILES1_H

#include <QMainWindow>
#include <string>
#include <cstring>

class CheckFiles1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit CheckFiles1(QWidget *parent = nullptr);

signals:
public slots:
    void init();
    void initDB();
    void initMkDir();
    void initKontrahent();
    void initZapisMiasta();
    void initZapisModel();
    void initZapisNrSeryjny();
    void initZapisProducenta();
    void initZapisWojewodztwa();
    void initZapisKraj();
    void initCheckFlagsInMiasto();
    void initCheckFlagsInWojewodztwa();
    void initCheckFlagsInKrajKontrahentShow();
    void initCheckFlagsInMiastoKontrahentShow();
    void initCheckFlagsInWojewodztwoKontrahentShow();
    void initCheckFlagsInKraj();
    int checkFlagsMiasto(int checkFlagsVarriable);
    int checkFlagsWojewodztwa(int checkFlagsVarriableWojewodztwo);
    int checkFlagsKraj(int checkFlagsVarriableKraj);
    void initUrzadzenie();
};

#endif // CHECKFILES1_H
//Info do Gita