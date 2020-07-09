#include "kontrahent.h"
#include "mainwindow.h"
#include "time.h"
#include "ui_kontrahent.h"
#include "kontrahentdodajmiasto.h"
#include "kontrahentdodajwojewodztwo.h"
#include "kontrahentshow.h"
#include "Info/info.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QTimer>
#include <QApplication>
#include <QtWidgets>





using namespace std;

time_t czasKontrahent;
tm timeinfoKontrahent;
int labelGodzinaKontrahent;
int labelDataKontrahent;
int wynikKontrahent;
int godzinaKontrahent, minutaKontrahent, sekundaKontrahent, dzienKontrahent, miesiacKontrahent, rokKontrahent;
int dzienTygodniaKontrahent;
string stringDzienTygodniaKontrahent;
string zmiennasKontrahent;

fstream plikKontrahent;

Kontrahent::Kontrahent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kontrahent)
{
     ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    wczytajMiasta();
    wczytajWojewodztwa();
}

Kontrahent::~Kontrahent()
{
    delete ui;
}

void Kontrahent::myfunctiontimer()
{
    time(&czasKontrahent);
    timeinfoKontrahent = *localtime(&czasKontrahent);
    godzinaKontrahent = timeinfoKontrahent.tm_hour;
    minutaKontrahent = timeinfoKontrahent.tm_min;
    sekundaKontrahent = timeinfoKontrahent.tm_sec;
    dzienKontrahent = timeinfoKontrahent.tm_mday;
    miesiacKontrahent = timeinfoKontrahent.tm_mon;
    rokKontrahent = timeinfoKontrahent.tm_year;
    dzienTygodniaKontrahent = timeinfoKontrahent.tm_wday;
    miesiacKontrahent = miesiacKontrahent + 1;
    rokKontrahent = rokKontrahent + 1900;

    zmianaLabela(godzinaKontrahent, minutaKontrahent, sekundaKontrahent, dzienKontrahent, miesiacKontrahent, rokKontrahent, dzienTygodniaKontrahent);
}
int Kontrahent::zmianaLabela(
    int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia)
{
    // Dodoać zera do sekund gdy mniej niz 10
    QString qStrMin = QString::number(minuta);
    QString qStrGodz = QString::number(godzina);
    QString qStrSek = QString::number(sekunda);
    QString qStrDzien = QString::number( dzien);
    QString qStrMiesiac = QString::number(miesiac);
    if (sekunda<10)
    {
        qStrSek = "0"+QString::number(sekunda);
    }
    if (minuta <10)
    {
        qStrMin = "0"+QString::number(minuta);
    }
    if (godzina<10)
    {
        qStrGodz = "0"+QString::number(godzina);
    }
    if (miesiac <10)
    {
        qStrMiesiac = "0"+QString::number(miesiac);
    }
    if (dzien <10)
    {
        qStrDzien = "0"+QString::number(dzien);
    }


ui->labelZegara->setText(qStrGodz + ":" + qStrMin + ":" + qStrSek);
    ui->labelDaty->setText(QString::number(rok) + "." + qStrMiesiac + "."
                           + qStrDzien);
    switch (dzienTygodnia) {
    case 1:
        stringDzienTygodniaKontrahent = "Poniedziałek";
        break;
    case 2:
        stringDzienTygodniaKontrahent = "Wtorek";
        break;
    case 3:
        stringDzienTygodniaKontrahent = "Środa";
        break;
    case 4:
        stringDzienTygodniaKontrahent = "Czwartek";
        break;
    case 5:
        stringDzienTygodniaKontrahent = "Piątek";
        break;
    case 6:
        stringDzienTygodniaKontrahent = "Sobota";
        break;
    case 0:
        stringDzienTygodniaKontrahent = "Niedziela";
        break;
    }
    ui->labelDzien->setText((stringDzienTygodniaKontrahent).c_str());
}

void Kontrahent::wczytajMiasta()
{
    //Wczytuje miasta z pliku
    plikKontrahent.open("C:/Qt/Pliki/ZapisMiasta.txt", ios::in);
    if (plikKontrahent.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikKontrahent, linia)) {
        ui->comboBoxWczytajMiasta->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }

    plikKontrahent.close();
}
void Kontrahent::wczytajWojewodztwa()
{
    //Wczytuje miasta z pliku
    plikKontrahent.open("C:/Qt/Pliki/ZapisWojewodztwa.txt", ios::in);
    if (plikKontrahent.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikKontrahent, linia)) {
        ui->comboBoxWczytajWojewodztwa->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }

    plikKontrahent.close();
}

void Kontrahent::on_pushButton_clicked()
{
    string kontrahent;
    //Zapisz
    cout<<"Zapisuje"<<endl;

    plikKontrahent.open("C:/Qt/Pliki/Kontrahent.txt", ios::out | ios::app);

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;


    //tymczasowo
    ui->lineEditWczytajNumer->setText("1");

ui->comboBoxPomoc->addItem(ui->lineEditWczytajNumer->text()) ;
ui->comboBoxPomoc->addItem(ui->lineEditWczytajNazwa_1->text()) ;
ui->comboBoxPomoc->addItem(ui->lineEditWczytajNazwa_2->text()) ;
ui->comboBoxPomoc->addItem(ui->lineEditWczytajNazwa_3->text()) ;
ui->comboBoxPomoc->addItem(ui->lineEditWczytajKraj->text()) ;
//Wczytaj wojewodztwo
ui->comboBoxPomoc->addItem(ui->comboBoxWczytajWojewodztwa->currentText());
//Wczytaj miasto
ui->comboBoxPomoc->addItem(ui->comboBoxWczytajMiasta->currentText());


ui->comboBoxPomoc->addItem(ui->lineEditWczytajKodPocztowy->text());
ui->comboBoxPomoc->addItem(ui->lineEditWczytajUlica->text()) ;
ui->comboBoxPomoc->addItem(ui->lineEditWczytajNrDomu->text());
ui->comboBoxPomoc->addItem(ui->lineEditWczytajTelefon->text());
ui->comboBoxPomoc->addItem(ui->lineEditWczytajTelefonDod->text());
ui->comboBoxPomoc->addItem(ui->lineEditWczytajEmail->text());
ui->comboBoxPomoc->addItem(ui->lineEditWczytajUrl->text());

plikKontrahent<<ui->lineEditWczytajNumer->text().toStdString() << endl;
plikKontrahent<<ui->lineEditWczytajNazwa_1->text().toStdString() << endl;
plikKontrahent<<ui->lineEditWczytajNazwa_2->text().toStdString() << endl;
plikKontrahent<<ui->lineEditWczytajNazwa_3->text().toStdString() << endl;
plikKontrahent<<ui->lineEditWczytajKraj->text().toStdString() << endl;
//Wczytaj wojewodztwo
plikKontrahent<<ui->comboBoxWczytajWojewodztwa->currentText().toStdString()<< endl;;

//Wczytaj miasto
plikKontrahent<<ui->comboBoxWczytajMiasta->currentText().toStdString()<< endl;;

plikKontrahent<<ui->lineEditWczytajKodPocztowy->text().toStdString() << endl;
plikKontrahent<<ui->lineEditWczytajUlica->text().toStdString() << endl;
plikKontrahent<<ui->lineEditWczytajNrDomu->text().toStdString() << endl;
plikKontrahent<<ui->lineEditWczytajTelefon->text().toStdString() << endl;
plikKontrahent<<ui->lineEditWczytajTelefonDod->text().toStdString() << endl;
plikKontrahent<<ui->lineEditWczytajEmail->text().toStdString() << endl;
plikKontrahent<<ui->lineEditWczytajUrl->text().toStdString() << endl;


iloscElementowWcombo = ui->comboBoxPomoc->count();


    for (int i = 0; i <= iloscElementowWcombo-1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;

    }
    plikKontrahent.close();

}

void Kontrahent::on_pushButton_2_clicked()
{
    //Wyjdz
    cout<<"Wychodze z Kontrahentów"<<endl;
    destroy();
}

void Kontrahent::on_actionDodaj_Miasto_triggered()
{
    // Kontarhaent Dodaj miasto // kontrahentdodajmiasto.
    cout<<"Dodoaje miasto zkontrahenta"<<endl;
    KontrahentDodajMiasto *kontrDodMiasto = new KontrahentDodajMiasto(this);
    kontrDodMiasto->show();

}

void Kontrahent::on_actionDodaj_Wojew_dztwo_triggered()
{
    cout<<"Dodoaje wojewdoztwo z kontrahenta"<<endl;
    KontrahentDodajWojewodztwo *kontrDodWoje = new KontrahentDodajWojewodztwo(this);
    kontrDodWoje->show();
}



void Kontrahent::on_lineEditWczytajNazwa_1_textChanged(const QString &arg1)
{
    cout<<"Zmiana textu"<<endl;
}

void Kontrahent::on_actionInfo_triggered()
{
Info *info= new Info(this);
    info->show();
}




void Kontrahent::on_comboBoxWczytajMiasta_highlighted(const QString &arg1)
{
     ui->comboBoxWczytajMiasta->clear();
     wczytajMiasta();
     //TODO: Posortować w comboBoxie miast

}
