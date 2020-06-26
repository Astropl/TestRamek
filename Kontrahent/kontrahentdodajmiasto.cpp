#include "kontrahentdodajmiasto.h"
#include "ui_kontrahentdodajmiasto.h"
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include <QFile>

using namespace std;

fstream plikOdczytDodajMiasto;

KontrahentDodajMiasto::KontrahentDodajMiasto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KontrahentDodajMiasto)
{
    ui->setupUi(this);
    cout<<"Wczytac itemy z pliku"<<endl;

    //---------------------------------------------------------

    plikOdczytDodajMiasto.open("C:/Qt/Pliki/ZapisMiasto.txt",ios::in);
    if(plikOdczytDodajMiasto.good()==false)
    {
        cout<<"Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikOdczytDodajMiasto,linia))
    {

        ui->comboBoxDodajMiasto->addItem(linia.c_str()) ;
        cout<<linia.c_str()<<endl;
        nr_lini ++;
    }
    plikOdczytDodajMiasto.close();
    //ui->comboBoxDodajMiasto->sor
}

KontrahentDodajMiasto::~KontrahentDodajMiasto()
{
    delete ui;
}

void KontrahentDodajMiasto::on_pushButton_clicked()
{
    cout << "Zapisuje i wychodze z okienka" << endl;
    // musze zapisać do pliku
    plikOdczytDodajMiasto.open("C:/Qt/Pliki/ZapisMiasta.txt", ios::out | ios::app);

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;

    iloscElementowWcombo = ui->comboBoxDodajMiasto->count();
    for (int i = 0; i <= iloscElementowWcombo-1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
        plikOdczytDodajMiasto << ui->comboBoxDodajMiasto->itemText(i).toStdString() << endl;
    }
    plikOdczytDodajMiasto.close();
    //ui->Jak zrobic aby comboxy na urzadzeniach się odswiezały
    //ui->comboBoxDodajMiasto->rep
    destroy();
}

void KontrahentDodajMiasto::on_pushButton_2_clicked()
{
    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.
    if (ui->lineEditDodajMiasto->text() != "") {
        cout << "Dodaje model analizatora" << endl;
        QString dodajMiasto = ui->lineEditDodajMiasto->text();

        ui->comboBoxDodajMiasto->addItem(dodajMiasto);
        ui->lineEditDodajMiasto->setText("");
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego miasta.");
    }

    //Próbuje srotowania
    //string  items[] = ui->comboBoxDodajMiasto->count();
}

void KontrahentDodajMiasto::on_comboBoxDodajMiasto_activated(const QString &arg1)
{
    //string[] items = ui->comboBoxDodajMiasto->getItems();
}
