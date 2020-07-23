#include "checkfiles1.h"
#include "checksystem.h"
#include <direct.h>
#include <fstream>
#include <iostream>
using namespace std;
fstream file;
CheckFiles1::CheckFiles1(QWidget *parent)
    : QMainWindow(parent)
{}

void CheckFiles1::initMkDir()
{
    mkdir("C:/Defaults");
    mkdir("C:/Defaults/Pliki");
}

void CheckFiles1::initKontrahent()
{
    file.open("C:/Defaults/Pliki/Kontrahent.txt", ios::out);
    if (file.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    file.close();
}
void CheckFiles1::initZapisMiasta()
{
    file.open("C:/Defaults/Pliki/ZapisMiasta.txt", ios::out);
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}

void CheckFiles1::initZapisModel()
{
    file.open("C:/Defaults/Pliki/ZapisModel.txt", ios::out);
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles1::initZapisNrSeryjny()
{
    file.open("C:/Defaults/Pliki/ZapisNrSeryjny.txt", ios::out);
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}

void CheckFiles1::initZapisProducenta()
{
    file.open("C:/Defaults/Pliki/ZapisProducenta.txt", ios::out);
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles1::initZapisWojewodztwa()
{
    file.open("C:/Defaults/Pliki/ZapisWojewodztwa.txt", ios::out);
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
    } else {
        cout << "Plik jest" << endl;
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
    CheckSystem *checkSystem = new CheckSystem();
    checkSystem ->show();


    cout << "Jestem w CheckFiles" << endl;

    //Sprawdzam czy pliki istnieją jezeli nie tworzę je.

    //Kontrahent.txt, ZapisMiasta, ZapisModel,ZapisNrSeryjny,ZapisProducenta,ZapisWojewodztwa
}