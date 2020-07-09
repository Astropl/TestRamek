#include "kontrahentdodajwojewodztwo.h"
#include "ui_kontrahentdodajwojewodztwo.h"
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QMessageBox>
#include <QApplication>
#include <QtWidgets>

using namespace std;

fstream plikOdczytDodajWojewodztwa;

KontrahentDodajWojewodztwo::KontrahentDodajWojewodztwo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KontrahentDodajWojewodztwo)
{
    ui->setupUi(this);

    cout<<"Wczytac itemy z pliku"<<endl;

    //---------------------------------------------------------

    plikOdczytDodajWojewodztwa.open("C:/Qt/Pliki/ZapisWojewodztwa.txt",ios::in);
    if(plikOdczytDodajWojewodztwa.good()==false)
    {
        cout<<"Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikOdczytDodajWojewodztwa,linia))
    {

        ui->comboBoxDodajWojewodztwa->addItem(linia.c_str()) ;
        cout<<linia.c_str()<<endl;
        nr_lini ++;
    }
    plikOdczytDodajWojewodztwa.close();
    //ui->comboBoxDodajMiasto->sor

}

KontrahentDodajWojewodztwo::~KontrahentDodajWojewodztwo()
{
    delete ui;
}

void KontrahentDodajWojewodztwo::on_pushButton_clicked()
{
    cout << "Zapisuje i wychodze z okienka" << endl;
    // musze zapisać do pliku
    plikOdczytDodajWojewodztwa.open("C:/Qt/Pliki/ZapisWojewodztwa.txt", ios::out | ios::app);

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;

    iloscElementowWcombo = ui->comboBoxDodajWojewodztwa->count();
    for (int i = 0; i <= iloscElementowWcombo-1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
        plikOdczytDodajWojewodztwa << ui->comboBoxDodajWojewodztwa->itemText(i).toStdString() << endl;
    }
    plikOdczytDodajWojewodztwa.close();
    //ui->Jak zrobic aby comboxy na urzadzeniach się odswiezały
    //ui->comboBoxDodajMiasto->rep
    destroy();

}

void KontrahentDodajWojewodztwo::on_pushButton_2_clicked()
{
   //comboBoxDodajWojewodztwa">

   //sprawdzam czy label dodawania modelu jest pusty - zrobione
   // Sprawdzić czy elent jest juz na liscie.
   if (ui->lineEditDodajWojewodztwa->text() != "") {
       cout << "Dodaje model analizatora" << endl;
       QString dodajWojewodztwo = ui->lineEditDodajWojewodztwa->text();

       ui->comboBoxDodajWojewodztwa->addItem(dodajWojewodztwo);
       ui->lineEditDodajWojewodztwa->setText("");
   } else {
       //wyswietl info ze pusty label
       QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego miasta.");
   }

   //Próbuje srotowania
   //string  items[] = ui->comboBoxDodajMiasto->count();
}
