#include "mainwindow.h"
//#include "Files/checksystemfiles1.h"
#include "Files/checkfiles1.h"
#include <QMessageBox>
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
//Info do Gita

//      1.DB.txt,
//      2.Kontrahent.txt,
//      3.Urzadzenie.txt
//      4.ZapisKraj.txt
//      5.ZapisMiasta.txt
//      6.ZapisWojewodztwa.txt
//      7.ZapisProducenta.txt
//      8.ZapisModel.txt,
//      9.ZapisNrSeryjny.txt
//      10.CheckFlagsInMiasto.txt
//      11.CheckFlagsInKraj.txt
//      12.CheckFlagsInWojewodztwa.txt
//      13.CheckFlagsInKrajKontrahentShow.txt
//      14.CheckFlagsInMiastoKontrahentShow.txt
//      15.CheckFlagsInWojewodztwoKontrahentShow.txt
//CheckFlagsInWojewodztwo();
//
//
//
//
//
