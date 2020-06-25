#include "urzadzenia.h"
#include "mainwindow.h"
#include "time.h"
#include "ui_urzadzenia.h"
#include "urzadzeniadodajmodel.h"
#include "urzadzeniadodajnrseryjny.h"
#include "urzadzeniadodajproducenta.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QTimer>

using namespace std;

string stringLabela4 = ("Producent: , Model: , Nr. Seryjny: ");
QString zaznaczono;
fstream plik;

time_t czasUrzadzenia;
tm timeinfo;
int labelGodzina;
int labelData;
int wynik;
int godzina, minuta, sekunda, dzien, miesiac, rok;
int dzienTygodnia;
string stringDzienTygodnia;
string zmiennas;

Urzadzenia::Urzadzenia(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Urzadzenia)
{
    ui->setupUi(this);
    ui->comboBox->addItem("");
    ui->comboBox_2->addItem("");
    ui->comboBox_3->addItem("");

    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================

    //Wczytuje modele z pliku
    plik.open("C:/Qt/Pliki/ZapisModel.txt", ios::in);
    if (plik.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plik, linia)) {
        ui->comboBox_2->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }

    plik.close();
    // wczytuj pliki z producenta
    plik.open("C:/Qt/Pliki/ZapisProducenta.txt", ios::in);
    if (plik.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia1;
    int nr_lini1 = 1;
    while (getline(plik, linia1)) {
        ui->comboBox->addItem(linia1.c_str());
        cout << linia1.c_str() << endl;
        nr_lini1++;
    }
    plik.close();
    //wczytaj numery seryjne z pliku
    plik.open("C:/Qt/Pliki/ZapisNrSeryjny.txt", ios::in);
    if (plik.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia2;
    int nr_lini2 = 1;
    while (getline(plik, linia2)) {
        ui->comboBox_3->addItem(linia2.c_str());
        cout << linia2.c_str() << endl;
        nr_lini2++;
    }
    plik.close();

    countriesListModel = new QStringListModel(this);

    ui->countriesList->setModel(countriesListModel);
    int row = countriesListModel->rowCount(); // pobieram liczbę wierszy

    countriesListModel->insertRow(row);                    // wstawiam dodatkowy wiersz na końcu
    QModelIndex index = countriesListModel->index(row, 0); // pobieram obiekt wstawionego indeksu
    countriesListModel->setData(index, QVariant("*"));
}
void Urzadzenia::myfunctiontimer()
{
    time(&czasUrzadzenia);
    timeinfo = *localtime(&czasUrzadzenia);
    godzina = timeinfo.tm_hour;
    minuta = timeinfo.tm_min;
    sekunda = timeinfo.tm_sec;
    dzien = timeinfo.tm_mday;
    miesiac = timeinfo.tm_mon;
    rok = timeinfo.tm_year;
    dzienTygodnia = timeinfo.tm_wday;
    miesiac = miesiac + 1;
    rok = rok + 1900;
    cout << godzina << endl;
    cout << minuta << endl;
    cout << sekunda << endl;
    cout << dzien << endl;
    cout << miesiac << endl;
    cout << rok << endl;
    cout << dzienTygodnia << endl;
    zmianaLabela(godzina, minuta, sekunda, dzien, miesiac, rok, dzienTygodnia);
}
int Urzadzenia::zmianaLabela(
    int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia)
{
    ui->labelZegara->setText(QString::number(godzina) + ":" + QString::number(minuta) + ":"
                             + QString::number(sekunda));
    ui->labelDaty->setText(QString::number(rok) + "." + QString::number(miesiac) + "."
                           + QString::number(dzien));
    switch (dzienTygodnia) {
    case 1:
        stringDzienTygodnia = "Poniedziałek";
        break;
    case 2:
        stringDzienTygodnia = "Wtorek";
        break;
    case 3:
        stringDzienTygodnia = "Środa";
        break;
    case 4:
        stringDzienTygodnia = "Czwartek";
        break;
    case 5:
        stringDzienTygodnia = "Piątek";
        break;
    case 6:
        stringDzienTygodnia = "Sobota";
        break;
    case 7:
        stringDzienTygodnia = "Niedziela";
        break;
    }
    ui->labelDzien->setText((stringDzienTygodnia).c_str());
}
Urzadzenia::~Urzadzenia()
{
    delete ui;
}

void Urzadzenia::on_BtnUrzaZapisz_clicked()
{
    cout << "Zapisz" << endl;
}

void Urzadzenia::on_BtnUrzaZamknij_clicked()
{
    destroy();
}

void Urzadzenia::on_countriesList_clicked(const QModelIndex &index)
{
    int rowCount = countriesListModel->rowCount();
    countriesListModel->insertRow(rowCount);
    countriesListModel->setData(index, QVariant("Cos innego")); // i ustawiam tekst na "*"

    ui->label_4->setText(zaznaczono + " " + ui->comboBox->currentText());
}

void Urzadzenia::on_comboBox_textActivated(const QString &arg1)
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText()
                         + ", Model: " + ui->comboBox_2->currentText()
                         + ", NumerSeryjny: " + ui->comboBox_3->currentText());
}

void Urzadzenia::on_comboBox_2_textActivated(const QString &arg1)
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText()
                         + ", Model: " + ui->comboBox_2->currentText()
                         + ", NumerSeryjny: " + ui->comboBox_3->currentText());
}

void Urzadzenia::on_comboBox_3_textActivated(const QString &arg1)
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText()
                         + ", Model: " + ui->comboBox_2->currentText()
                         + ", NumerSeryjny: " + ui->comboBox_3->currentText());
}

void Urzadzenia::on_actionDodaj_Model_triggered()
{
    UrzadzeniaDodajModel *urzDodModel = new UrzadzeniaDodajModel(this);
    urzDodModel->show();
}

void Urzadzenia::on_actionDodaj_Producenta_triggered()
{
    UrzadzeniaDodajProducenta *urzDodProd = new UrzadzeniaDodajProducenta(this);
    urzDodProd->show();
}

void Urzadzenia::on_actionDodaj_Numer_Seryjny_triggered()
{
    UrzadzeniaDodajNrSeryjny *urzDodNrSer = new UrzadzeniaDodajNrSeryjny(this);
    urzDodNrSer->show();
}
