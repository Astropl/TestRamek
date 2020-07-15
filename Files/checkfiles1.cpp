#include "checkfiles1.h"
#include <direct.h>
#include <fstream>
#include <iostream>
using namespace std;
CheckFiles1::CheckFiles1(QWidget *parent)
    : QMainWindow(parent)
{}
void CheckFiles1::init()
{
    cout << "Jestem w CheckFiles" << endl;

    fstream file;
    mkdir("C:/Defaults");
    mkdir("C:/Defaults/Pliki");
    //Sprawdzam czy pliki istnieją jezeli nie tworzę je.

    file.open("C:/Defaults/Pliki/Kontrahent.txt", ios::out);
    if (file.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    file.close();
    //Kontrahent.txt, ZapisMiasta, ZapisModel,ZapisNrSeryjny,ZapisProducenta,ZapisWojewodztwa

    file.open("C:/Defaults/Pliki/ZapisMiasta.txt", ios::out);
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
    //
    file.open("C:/Defaults/Pliki/ZapisModel.txt", ios::out);
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
    //
    file.open("C:/Defaults/Pliki/ZapisNrSeryjny.txt", ios::out);
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
    //
    file.open("C:/Defaults/Pliki/ZapisProducenta.txt", ios::out);
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
    //
    file.open("C:/Defaults/Pliki/ZapisWojewodztwa.txt", ios::out);
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
    } else {
        cout << "Plik jest" << endl;
    }
    file.close();
}