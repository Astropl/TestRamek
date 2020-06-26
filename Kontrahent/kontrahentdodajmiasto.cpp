#include "kontrahentdodajmiasto.h"
#include "ui_kontrahentdodajmiasto.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QMessageBox>

using namespace std;

fstream plikOdczyt;

KontrahentDodajMiasto::KontrahentDodajMiasto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentDodajMiasto)
{
    ui->setupUi(this);

    cout << "Wczytac itemy z pliku" << endl;

    //---------------------------------------------------------

    plikOdczyt.open("C:/Qt/Pliki/ZapisMiasto.txt", ios::in);

    if (plikOdczyt.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikOdczyt, linia)) {
        ui->comboBoxDodajMiasto->addItem(linia.c_str());
        cout << linia.c_str() << endl;

        nr_lini++;
    }
    plikOdczyt.close();

    //--------------------------------------------------------
}

KontrahentDodajMiasto::~KontrahentDodajMiasto()
{
    delete ui;
}

void KontrahentDodajMiasto::on_pushButton_clicked()
{
    destroy();
}

void KontrahentDodajMiasto::on_pushButton_2_clicked()
{
    //Dodoaj miasto
    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.
    if (ui->lineEditDodajMiasto->text() != "") {
        cout << "Dodaje model analizatora" << endl;
        QString dodajModel = ui->lineEditDodajMiasto->text();

        ui->comboBoxDodajMiasto->addItem(dodajModel);
        ui->lineEditDodajMiasto->setText("");
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego modelu.");
    }
}
