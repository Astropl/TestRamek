#include "urzadzeniadodajmodel.h"
#include "ui_urzadzeniadodajmodel.h"
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include <QFile>

using namespace std;

fstream plikOdczyt;

UrzadzeniaDodajModel::UrzadzeniaDodajModel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaDodajModel)
{
    ui->setupUi(this);
    cout<<"Wczytac itemy z pliku"<<endl;

    //---------------------------------------------------------

    plikOdczyt.open("C:/Defaults/Pliki/ZapisModel.txt",ios::in);
    if(plikOdczyt.good()==false)
    {
        cout<<"Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikOdczyt,linia))
    {

         ui->comboBoxDodajModel->addItem(linia.c_str()) ;
            cout<<linia.c_str()<<endl;
       nr_lini ++;
    }
    plikOdczyt.close();

    //--------------------------------------------------------
}

UrzadzeniaDodajModel::~UrzadzeniaDodajModel()
{
    delete ui;
}

void UrzadzeniaDodajModel::on_pushButton_clicked()
{ //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.
    if (ui->lineEditDodajModel->text() != "") {
        cout << "Dodaje model analizatora" << endl;
        QString dodajModel = ui->lineEditDodajModel->text();

        ui->comboBoxDodajModel->addItem(dodajModel);
        ui->lineEditDodajModel->setText("");
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego modelu.");
    }
}

void UrzadzeniaDodajModel::on_pushButton_2_clicked()
{
    cout << "Zapisuje i wychodze z okienka" << endl;
    // musze zapisać do pliku
    plikOdczyt.open("C:/Defaults/Pliki/ZapisModel.txt", ios::out | ios::app);

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;

    iloscElementowWcombo = ui->comboBoxDodajModel->count();
    for (int i = 0; i <= iloscElementowWcombo-1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
       plikOdczyt << ui->comboBoxDodajModel->itemText(i).toStdString() << endl;
    }
    plikOdczyt.close();
    //ui->Jak zrobic aby comboxy na urzadzeniach się odswiezały

    destroy();
}
//Info do Gita