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
    void initMkDir();
    void initKontrahent();
    void initZapisMiasta();
    void initZapisModel();
    void initZapisNrSeryjny();
    void initZapisProducenta();
    void initZapisWojewodztwa();
    void initZapisKraj();
    void initCheckFlagsInMiasto();
    void initCheckFlagsInWojewodztwo();
    void initCheckFlagsInKraj();
    int checkFlagsMiasto(int checkFlagsVarriable);
    int checkFlagsWojewodztwo(int checkFlagsVarriableWojewodztwo);
    int checkFlagsKraj(int checkFlagsVarriableKraj);
};

#endif // CHECKFILES1_H
//Info do Gita