#include "checkfiles1.h"
#include "checksystem.h"
#include <direct.h>
#include <fstream>
#include <iostream>

#include <string>
using namespace std;
fstream file;
QString file1 = "C:/Defaults/Pliki/1.DB.txt";
QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
QString file4 = "C:/Defaults/Pliki/4.ZapisKraj.txt";
QString file5 = "C:/Defaults/Pliki/5.ZapisMiasta.txt";
QString file6 = "C:/Defaults/Pliki/6.ZapisWojewodztwa.txt";
QString file7 = "C:/Defaults/Pliki/7.ZapisProducenta.txt";
QString file8 = "C:/Defaults/Pliki/8.ZapisModel.txt";
QString file9 = "C:/Defaults/Pliki/9.ZapisNrSeryjny.txt";
QString file10 = "C:/Defaults/Pliki/10.CheckFlagsInMiasto.txt";
QString file11 = "C:/Defaults/Pliki/11.CheckFlagsInKraj.txt";
QString file12 = "C:/Defaults/Pliki/12.CheckFlagsInWojewodztwa.txt";
QString file13 = "C:/Defaults/Pliki/13.CheckFlagsInKrajKontrahentShow.txt";
QString file14 = "C:/Defaults/Pliki/14.CheckFlagsInMiastoKontrahentShow.txt";
QString file15 = "C:/Defaults/Pliki/15.CheckFlagsInWojewodztwoKontrahentShow.txt";
QString file16 = "C:/Defaults/Pliki/16.CheckFlagsInProducentUrzadzenia.txt";
QString file17 = "C:/Defaults/Pliki/17.CheckFlagsInModelUrzadzenia.txt";


CheckFiles1::CheckFiles1(QWidget *parent)
    : QMainWindow(parent)
{}

void CheckFiles1::initMkDir()
{/*//TODO: Dodoac pliki do Katalogów
    CheckFlagsInMiastoKontrahentShow
        CheckFlagsInWojewodztwoKontrahentShow
            CheckFlagsInKrajKontrahentShow*/



    mkdir("C:/Defaults");
    mkdir("C:/Defaults/Pliki");
}
void CheckFiles1::initDB()
{
    file.open(file1.toStdString()); //, ios::app
    if (file.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        file.open(file1.toStdString(), ios::app);
        //exit(0);
    }
    file.close();
}


void CheckFiles1::initKontrahent()
{
    file.open(file2.toStdString()); //, ios::app
    if (file.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        file.open(file2.toStdString(), ios::app);
        //exit(0);
    }
    file.close();
}
void CheckFiles1::initUrzadzenie()
{
    file.open(file3.toStdString()); //, ios::app
    if (file.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        file.open(file3.toStdString(), ios::app);
        //exit(0);
    }
    file.close();
}
void CheckFiles1::initZapisKraj()
{
    file.open(file4.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file4.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}



void CheckFiles1::initZapisMiasta()
{
    file.open(file5.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file5.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles1::initZapisWojewodztwa()
{
    file.open(file6.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file6.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles1::initZapisProducenta()
{
    file.open(file7.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file7.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles1::initZapisModel()
{
    file.open(file8.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file8.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles1::initZapisNrSeryjny()
{
    file.open(file9.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file9.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles1::initCheckFlagsInMiasto()
{
    file.open(file10.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file10.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
    cout << "Plik Check Flags In Miasto Jest." << endl;
}




void CheckFiles1::initCheckFlagsInKraj()
{
    file.open(file11.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file11.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}
void CheckFiles1::initCheckFlagsInModelUrzadzenia()
{
    file.open(file17.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file17.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}
void CheckFiles1::initCheckFlagsInProducentUrzadzenia()
{
    file.open(file16.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file16.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}


void CheckFiles1::initCheckFlagsInWojewodztwa()
{
    file.open(file12.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file12.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
    cout << "Plik Check Flags In Wojewodztwo Jest." << endl;
}
void CheckFiles1::initCheckFlagsInKrajKontrahentShow()
{
    file.open(file13.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file13.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
    cout << "Plik Check Flags In Wojewodztwo Jest." << endl;
}
void CheckFiles1::initCheckFlagsInMiastoKontrahentShow()
{
    file.open(file14.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file14.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
    cout << "Plik Check Flags In Wojewodztwo Jest." << endl;
}

int CheckFiles1::checkFlagsProducent(int checkFlagsVarriableProducent)
{
    //cout << " W CheckFiles1: CheckFlagsProducent" << endl;

    file.open(file16.toStdString(),
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {

        //cout << linia << endl;
        if (linia == "0") {
            //cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            //cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();
}

int CheckFiles1::checkFlagsModel(int checkFlagsVarriableModel)
{
    //cout << " W CheckFiles1: CheckFlagsProducent" << endl;

    file.open(file16.toStdString(),
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {

        //cout << linia << endl;
        if (linia == "0") {
            //cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            //cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();
}

void CheckFiles1::initCheckFlagsInWojewodztwoKontrahentShow()
{
    file.open(file15.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file15.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
    cout << "Plik Check Flags In Wojewodztwo Jest." << endl;
}
 void CheckFiles1::initCheckFlagsProducent()
 {
     file.open(file16.toStdString());
     if (file.good() == false) {
         cout << "Brak pliku" << endl;
         file.open(file16.toStdString(), ios::app);
     } else {
        // cout << "Plik jest" << endl;
     }
     file << "0" << endl;
     file.close();
     cout << "Plik Check Flags In Produckt Jest." << endl;
 }


int CheckFiles1::checkFlagsWojewodztwa(int checkFlagsVarriableWojewodztwo)
{
    //cout<<" W checkfiles1:: checkFlags Wojewdoztwa"<<endl;
    file.open(file12.toStdString(),
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {

        //cout << linia << endl;
        if (linia == "0") {
            //cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            //cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();


}
int CheckFiles1::checkFlagsMiasto(int checkFlagsVarriableMiasto)
{
    //cout << " W CheckFiles1: CheckFlags" << endl;

    file.open(file10.toStdString(),
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {

        //cout << linia << endl;
        if (linia == "0") {
            //cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            //cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();

}


int CheckFiles1::checkFlagsKraj(int checkFlagsVarriableKraj)
{
    //cout << " W CheckFiles1: CheckFlags" << endl;

    file.open(file11.toStdString(),
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {

        //cout << linia << endl;
        if (linia == "0") {
           // cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
           // cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();

}

void CheckFiles1::init()
{
    initMkDir();
    initDB();//
    initKontrahent();//
    initUrzadzenie();//
    initZapisKraj();//
    initZapisMiasta();//
    initZapisWojewodztwa();//
    initZapisModel();//
    initZapisNrSeryjny();//
    initZapisProducenta();//
    initCheckFlagsInKrajKontrahentShow();
    initCheckFlagsInMiastoKontrahentShow();
    initCheckFlagsInWojewodztwoKontrahentShow();
    initCheckFlagsInMiasto();
    initCheckFlagsInWojewodztwa();
    initCheckFlagsInKraj();
    initCheckFlagsProducent();

    initCheckFlagsInModelUrzadzenia();
    initCheckFlagsInProducentUrzadzenia();


    // i tak samo jak wyzej ale do modelu

    CheckSystem *checkSystem = new CheckSystem();
    checkSystem->show();

    cout << "Jestem w CheckFiles" << endl;

    //Sprawdzam czy pliki istnieją jezeli nie tworzę je.

    //
}

//Info do Gita