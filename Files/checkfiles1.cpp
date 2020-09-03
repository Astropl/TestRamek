#include "checkfiles1.h"
#include "checksystem.h"
#include <direct.h>
#include <fstream>
#include <iostream>

#include <string>
using namespace std;
fstream file;

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

void CheckFiles1::initKontrahent()
{
    file.open("C:/Defaults/Pliki/Kontrahent.txt"); //, ios::app
    if (file.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        file.open("C:/Defaults/Pliki/Kontrahent.txt", ios::app);
        //exit(0);
    }
    file.close();
}
void CheckFiles1::initZapisMiasta()
{
    file.open("C:/Defaults/Pliki/ZapisMiasta.txt");
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open("C:/Defaults/Pliki/ZapisMiasta.txt", ios::app);
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}

void CheckFiles1::initZapisModel()
{
    file.open("C:/Defaults/Pliki/ZapisModel.txt");
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open("C:/Defaults/Pliki/ZapisModel.txt", ios::app);
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles1::initZapisNrSeryjny()
{
    file.open("C:/Defaults/Pliki/ZapisNrSeryjny.txt");
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open("C:/Defaults/Pliki/ZapisNrSeryjny.txt", ios::app);
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}

void CheckFiles1::initZapisProducenta()
{
    file.open("C:/Defaults/Pliki/ZapisProducenta.txt");
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open("C:/Defaults/Pliki/ZapisProducenta.txt", ios::app);
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles1::initZapisWojewodztwa()
{
    file.open("C:/Defaults/Pliki/ZapisWojewodztwa.txt");
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open("C:/Defaults/Pliki/ZapisWojewodztwa.txt", ios::app);
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles1::initZapisKraj()
{
    file.open("C:/Defaults/Pliki/ZapisKraj.txt");
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open("C:/Defaults/Pliki/ZapisKraj.txt", ios::app);
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}

void CheckFiles1::initCheckFlagsInKraj()
{
    file.open("C:/Defaults/Pliki/ZapisKraj.txt");
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open("C:/Defaults/Pliki/ZapisKraj.txt", ios::app);
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}


void CheckFiles1::initCheckFlagsInMiasto()
{
    file.open("C:/Defaults/Pliki/CheckFlagsInMiasto.txt");
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open("C:/Defaults/Pliki/CheckFlagsInMiasto.txt", ios::app);
    } else {
        cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
    cout << "Plik Check Flags In Miasto Jest." << endl;
}

void CheckFiles1::initCheckFlagsInWojewodztwo()
{
    file.open("C:/Defaults/Pliki/CheckFlagsInWojewodztwo.txt");
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open("C:/Defaults/Pliki/CheckFlagsInWojewodztwo.txt", ios::app);
    } else {
        cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
    cout << "Plik Check Flags In Wojewodztwo Jest." << endl;
}


int CheckFiles1::checkFlagsWojewodztwo(int checkFlagsVarriableWojewodztwo)
{
    cout<<" W checkfiles1:: checkFlags Wojewdoztwo"<<endl;
    file.open("C:/Defaults/Pliki/CheckFlagsInWojewodztwo.txt",
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {

        cout << linia << endl;
        if (linia == "0") {
            cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();


}
int CheckFiles1::checkFlagsMiasto(int checkFlagsVarriableMiasto)
{
    cout << " W CheckFiles1: CheckFlags" << endl;

    file.open("C:/Defaults/Pliki/CheckFlagsInMiasto.txt",
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {

        cout << linia << endl;
        if (linia == "0") {
            cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();

}


int CheckFiles1::checkFlagsKraj(int checkFlagsVarriableKraj)
{
    cout << " W CheckFiles1: CheckFlags" << endl;

    file.open("C:/Defaults/Pliki/CheckFlagsInKraj.txt",
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {

        cout << linia << endl;
        if (linia == "0") {
            cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();

}

void CheckFiles1::init()
{
    initMkDir();
    initKontrahent();
    initZapisMiasta();
    initZapisModel();
    initZapisNrSeryjny();
    initZapisProducenta();
    initZapisWojewodztwa();
    initCheckFlagsInMiasto();
    initCheckFlagsInWojewodztwo();
    initCheckFlagsInKraj();
    initUrzadzenie();
    CheckSystem *checkSystem = new CheckSystem();
    checkSystem->show();

    cout << "Jestem w CheckFiles" << endl;

    //Sprawdzam czy pliki istnieją jezeli nie tworzę je.

    //Kontrahent.txt, ZapisMiasta, ZapisModel,ZapisNrSeryjny,ZapisProducenta,ZapisWojewodztwa, CheckFlagsInMiasto.txt
}
void CheckFiles1::initUrzadzenie()
{
    file.open("C:/Defaults/Pliki/Urzadzenie.txt"); //, ios::app
    if (file.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        file.open("C:/Defaults/Pliki/Urzadzenie.txt", ios::app);
        //exit(0);
    }
    file.close();

}
//Info do Gita