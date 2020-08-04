#include "kontrahent.h"
#include "Info/info.h"
#include "Timery/timedate.h"
#include "kontrahentdodajmiasto.h"
#include "kontrahentdodajwojewodztwo.h"
#include "kontrahentshow.h"
#include "mainwindow.h"
#include "time.h"
#include "ui_kontrahent.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QApplication>
#include <QString>
#include <QTimer>
#include <QtWidgets>
//#include "stdafx.h"
#include "QByteArrayList"
#include <algorithm>
#include <vector>

using namespace std;
//using namespace System;
//using namespace System::Collections;

int iloscKontrahentow = 0;
//int labelGodzina;
//int labelData;
//int wynikKontrahent;
//int godzinaKontrahent, minutaKontrahent, sekundaKontrahent, dzienKontrahent, miesiacKontrahent, rokKontrahent;
//int dzienTygodniaKontrahent;
//string stringDzienTygodniaKontrahent;
//string zmiennasKontrahent;

fstream plikKontrahent;

Kontrahent::Kontrahent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Kontrahent)
{
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    wczytajMiasta();
    wczytajWojewodztwa();
    howMuchKontrahent();
    //    iloscKontrahentow++;
    //    ui->lineEditWczytajNumer->setText(QString::number(iloscKontrahentow));
}

Kontrahent::~Kontrahent()
{
    delete ui;
}

void Kontrahent::howMuchKontrahent()
{
    //TODO: Okreslic ile kontrahentow jest
    plikKontrahent.open("C:/Defaults/Pliki/Kontrahent.txt", ios::in);
    if (plikKontrahent.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikKontrahent, linia)) {
        iloscKontrahentow++;

        //ui->comboBoxWczytajMiasta->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }
    iloscKontrahentow = iloscKontrahentow / 14;
    ui->label_16->setText(QString::number(iloscKontrahentow));
    plikKontrahent.close();

    iloscKontrahentow++;
    ui->lineEditWczytajNumer->setText(QString::number(iloscKontrahentow));
}

void Kontrahent::myfunctiontimer()
{
    time_t czas;
    tm timeinfo;
    QString qStrMin, qStrGodz, qStrSek, qStrDzien, qStrMiesiac, stringDzienTygodnia;

    TimeDate *timeDate = new TimeDate();

    time(&czas);
    timeinfo = *localtime(&czas);
    int godzina = timeinfo.tm_hour;
    int minuta = timeinfo.tm_min;
    int sekunda = timeinfo.tm_sec;
    int dzien = timeinfo.tm_mday;
    int miesiac = timeinfo.tm_mon;
    int rok = timeinfo.tm_year;
    int dzienTygodnia = timeinfo.tm_wday;
    miesiac = miesiac + 1;
    rok = rok + 1900;
    dzienTygodnia = dzienTygodnia + 1;

    qStrMin = timeDate->changeStringsMin(minuta);
    qStrSek = timeDate->changeStringsSek(sekunda);
    qStrDzien = timeDate->changeStringsDzien(dzien);
    qStrGodz = timeDate->changeStringsGodz(godzina);
    qStrMiesiac = timeDate->changeStringsMiesiac(miesiac);
    stringDzienTygodnia = timeDate->changeStringsDzienTygodnia(dzienTygodnia);

    ui->labelZegara->setText(qStrGodz + ":" + qStrMin + ":" + qStrSek);
    ui->labelDaty->setText(QString::number(rok) + "." + qStrMiesiac + "." + qStrDzien);

    ui->labelDzien->setText(stringDzienTygodnia);
}

void Kontrahent::wczytajMiasta()
{
    //Wczytuje miasta z pliku
    plikKontrahent.open("C:/Defaults/Pliki/ZapisMiasta.txt", ios::in);
    if (plikKontrahent.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
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
    plikKontrahent.open("C:/Defaults/Pliki/ZapisWojewodztwa.txt", ios::in);
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
    cout << "Zapisuje" << endl;

    plikKontrahent.open("C:/Defaults/Pliki/Kontrahent.txt", ios::out | ios::app);

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;

    //TODO: Przypisac automatyczą numeracje WCZYTAJNUMER
    //tymczasowo

    ui->comboBoxPomoc->addItem(ui->lineEditWczytajNumer->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajNazwa_1->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajImie->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajNazwisko->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajKraj->text());
    //Wczytaj wojewodztwo
    ui->comboBoxPomoc->addItem(ui->comboBoxWczytajWojewodztwa->currentText());
    //Wczytaj miasto
    ui->comboBoxPomoc->addItem(ui->comboBoxWczytajMiasta->currentText());

    ui->comboBoxPomoc->addItem(ui->lineEditWczytajKodPocztowy->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajUlica->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajNrDomu->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajTelefon->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajTelefonDod->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajEmail->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajUrl->text());

    //TODO: Sprawdzam czy moge ominac comboBox Pomoc

    //plikKontrahent<<ui->

    plikKontrahent << ui->lineEditWczytajNumer->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajNazwa_1->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajImie->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajNazwisko->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajKraj->text().toStdString() << endl;
    //Wczytaj wojewodztwo
    plikKontrahent << ui->comboBoxWczytajWojewodztwa->currentText().toStdString() << endl;
    ;

    //Wczytaj miasto
    plikKontrahent << ui->comboBoxWczytajMiasta->currentText().toStdString() << endl;
    ;

    plikKontrahent << ui->lineEditWczytajKodPocztowy->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajUlica->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajNrDomu->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajTelefon->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajTelefonDod->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajEmail->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajUrl->text().toStdString() << endl;

    iloscElementowWcombo = ui->comboBoxPomoc->count();

    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
    }
    plikKontrahent.close();
    ui->lineEditWczytajNumer->setText(QString::number(iloscKontrahentow));
}

void Kontrahent::on_pushButton_2_clicked()
{
    //Wyjdz
    cout << "Wychodze z Kontrahentów" << endl;
    timer->stop();
    destroy();
}

void Kontrahent::on_actionDodaj_Miasto_triggered()
{
    // Kontarhaent Dodaj miasto // kontrahentdodajmiasto.
    cout << "Dodoaje miasto zkontrahenta" << endl;
    KontrahentDodajMiasto *kontrDodMiasto = new KontrahentDodajMiasto(this);
    kontrDodMiasto->show();
}

void Kontrahent::on_actionDodaj_Wojew_dztwo_triggered()
{
    cout << "Dodoaje wojewdoztwo z kontrahenta" << endl;
    KontrahentDodajWojewodztwo *kontrDodWoje = new KontrahentDodajWojewodztwo(this);
    kontrDodWoje->show();
}

void Kontrahent::on_lineEditWczytajNazwa_1_textChanged(const QString) // (const QString &arg1)
{
    cout << "Zmiana textu" << endl;
}

void Kontrahent::on_actionInfo_triggered()
{
    Info *info = new Info(this);
    info->show();
}

void Kontrahent::on_comboBoxWczytajMiasta_highlighted(const QString) //(const QString &arg1)
{
 cout << "Otrzymanie highland przycisku wczytaj Miasta" << endl;
}

//Info do Gita
void Kontrahent::on_comboBoxWczytajMiasta_activated(const QString) //(const QString &arg1)
{
    cout << "Aktywacja przycisku wczytaj Miasta" << endl;
    QStringList listaMiast = QStringList();

    //     //TODO: tutuaj zrobic sortowanie. Posortować w comboBoxie miast


    //TODO: Sortowanie. A moze zczytac wszytsko do tabeli o wielkosci = ilosci elementow w combobox. Wyciagnac pierwsze litery na stringach i posortowac a potem wyczyscic comboboxa i potem wkleic te dane posortowane juz? ::Sprawzić

    int ostatniindex = ui->comboBoxWczytajMiasta->count()-1;
    for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
        listaMiast.push_back(ui->comboBoxWczytajMiasta->itemText(iZmienna).toUtf8());
    }
    sort(listaMiast.begin(), listaMiast.end());
//    for (int jZmienna = 0; jZmienna <= listaMiast.count() - 1; jZmienna++) {
//        QVariant some = listaMiast.at(jZmienna);
//    }
    ui->comboBoxWczytajMiasta->clear();
    for (int kZmienna = 0; kZmienna <= listaMiast.count()-1; kZmienna++) {
//        ui->comboBoxWczytajMiasta->insertItem(ui->comboBoxWczytajMiasta->InsertAtCurrent,
//                                              listaMiast.takeAt(kZmienna).toLocal8Bit().constData());

ui->comboBoxWczytajMiasta->addItem(listaMiast.at(kZmienna));
    }
}
