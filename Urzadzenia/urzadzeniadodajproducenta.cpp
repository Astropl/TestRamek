#include "urzadzeniadodajproducenta.h"
#include "ui_urzadzeniadodajproducenta.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QMessageBox>

using namespace std;

fstream plikProducent;

UrzadzeniaDodajProducenta::UrzadzeniaDodajProducenta(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaDodajProducenta)
{
    ui->setupUi(this);

    plikProducent.open("C:/Defaults/Pliki/ZapisProducenta.txt", ios::in);

    if (plikProducent.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //return(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikProducent, linia)) {
        ui->comboBoxDodajProdcuenta->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }
    plikProducent.close();
}

UrzadzeniaDodajProducenta::~UrzadzeniaDodajProducenta()
{
    delete ui;
}

void UrzadzeniaDodajProducenta::on_pushButton_2_clicked()
{
    // Zapisz i zamknij
    cout << "Zapisuje i wychodze z okienka" << endl;
    // musze zapisać do pliku
    plikProducent.open("C:/Defaults/Pliki/ZapisProducenta.txt", ios::out | ios::app);
    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;
    iloscElementowWcombo = ui->comboBoxDodajProdcuenta->count();
    for (int i = 0; i <= iloscElementowWcombo-1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
        plikProducent << ui->comboBoxDodajProdcuenta->itemText(i).toStdString() << endl;
    }
    plikProducent.close();
    destroy();
}

void UrzadzeniaDodajProducenta::on_pushButton_clicked()
{
    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.
    if (ui->lineEditDodajProducenta->text() != "") {
        cout << "Dodaje model analizatora" << endl;
        QString dodajModel = ui->lineEditDodajProducenta->text();

        ui->comboBoxDodajProdcuenta->addItem(dodajModel);
        ui->lineEditDodajProducenta->setText("");
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego modelu.");
    }
}
//Info do Gita