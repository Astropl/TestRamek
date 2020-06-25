#include "urzadzeniadodajnrseryjny.h"
#include "ui_urzadzeniadodajnrseryjny.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QMessageBox>

using namespace std;
fstream plikNrSeryjny;

UrzadzeniaDodajNrSeryjny::UrzadzeniaDodajNrSeryjny(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaDodajNrSeryjny)
{
    ui->setupUi(this);

    plikNrSeryjny.open("C:/Qt/Pliki/ZapisNrSeryjny.txt", ios::in);

    if (plikNrSeryjny.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //return(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikNrSeryjny, linia)) {
        ui->comboBoxDodajNrSeryjny->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }
    plikNrSeryjny.close();
}

UrzadzeniaDodajNrSeryjny::~UrzadzeniaDodajNrSeryjny()
{
    delete ui;
}

void UrzadzeniaDodajNrSeryjny::on_pushButton_clicked()
{
    // Dodoaj do ComboBoxa
    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.
    if (ui->lineEditDodajNrSeryjny->text() != "") {
        cout << "Dodaje model analizatora" << endl;
        QString dodajModel = ui->lineEditDodajNrSeryjny->text();

        ui->comboBoxDodajNrSeryjny->addItem(dodajModel);
        ui->lineEditDodajNrSeryjny->setText("");
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego modelu.");
    }
}

void UrzadzeniaDodajNrSeryjny::on_pushButton_2_clicked()
{
    // Zapisz i zamknij
    cout << "Zapisuje i wychodze z okienka" << endl;
    // musze zapisać do pliku
    plikNrSeryjny.open("C:/Qt/Pliki/ZapisNrSeryjny.txt", ios::out | ios::app);
    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;
    iloscElementowWcombo = ui->comboBoxDodajNrSeryjny->count();
    for (int i = 0; i <= iloscElementowWcombo; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
        plikNrSeryjny << ui->comboBoxDodajNrSeryjny->itemText(i).toStdString() << endl;
    }
    plikNrSeryjny.close();
    destroy();
}
