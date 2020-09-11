#include "kontrahent.h"
#include "Files/checkfiles1.h"
#include "Info/info.h"
#include "Timery/timedate.h"
#include "kontrahentdodajkraj.h"
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

int iloscKontrahentow = 0;
int checkFlagsVarriableMiasto = 0;
int checkFlagsVarriableWojewodztwo = 0;
int checkFlagsVarriableKraj = 0;



fstream plikKontrahent;
fstream checkFlags;
int zmiennaDoHighlandWczytajMiasta = 1;


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
    QString file1 = "C:/Defaults/Pliki/1.DB.txt";
    QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
    QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
    QString file4 = "C:/Defaults/Pliki/4.ZapisKraj.txt";
    QString file5 = "C:/Defaults/Pliki/5.ZapisMiasta.txt";
    QString file6 = "C:/Defaults/Pliki/6.ZapisWojewodztwa.txt";
    QString file7 = "C:/Defaults/Pliki/7.ZapisProducenta.txt";
    QString file8 = "C:/Defaults/Pliki/8.ZapisModel.txt";
    QString file9 = "C:/Defaults/Pliki/9.ZapisNrSeryjny.txt";
    QString file10 = "C:/Defaults/Pliki/10.CheckFlagsInMiasto.txt";
    QString file11 = "C:/Defaults/Pliki/11.CheckFlagsInKraj.txt";
    QString file12 = "C:/Defaults/Pliki/12.CheckFlagsInWojewodztwa.txt";
    QString file13 = "C:/Defaults/Pliki/13.CheckFlagsInKrajKontrahentShow.txt";
    QString file14 = "C:/Defaults/Pliki/14.CheckFlagsInMiastoKontrahentShow.txt";
    QString file15 = "C:/Defaults/Pliki/15.CheckFlagsInWojewodztwoKontrahentShow.txt";

    wczytajMiasta();
    wczytajWojewodztwa();
    wczytajKraj();
    ui->comboBoxWczytajMiasta->currentIndex();
    ui->comboBoxWczytajWojewodztwa->currentIndex();
    ui->comboBoxWczytajKraj->currentIndex();
    howMuchKontrahent();
    ui->comboBoxWczytajKraj->setCurrentText("Brak");
    ui->comboBoxWczytajWojewodztwa->setCurrentText("Brak");
    ui->comboBoxWczytajMiasta->setCurrentText("Brak");
    //    iloscKontrahentow++;
    //    ui->lineEditWczytajNumer->setText(QString::number(iloscKontrahentow));
}

Kontrahent::~Kontrahent()
{
    delete ui;
}

void Kontrahent::howMuchKontrahent()
{QString file1 = "C:/Defaults/Pliki/2.Kontrahent.txt";

    plikKontrahent.open(file1.toStdString(), ios::in); //plik kontrahent
     //plikKontrahent.open("C:/Defaults/Pliki/2.Kontrahent.txt", ios::in); //plik kontrahent
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

void Kontrahent::wczytajKraj()
{
    //Wczytuje Kraje z pliku
    plikKontrahent.open(file4.toStdString(), ios::in);
    if (plikKontrahent.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikKontrahent, linia)) {
        ui->comboBoxWczytajKraj->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }

    plikKontrahent.close();
    ui->comboBoxWczytajKraj->currentIndex();
}

void Kontrahent::wczytajMiasta()
{
    //Wczytuje miasta z pliku
    plikKontrahent.open(file5.toStdString(), ios::in);
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
    plikKontrahent.open(file6.toStdString(), ios::in);
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

    plikKontrahent.open(file2.toStdString(), ios::out | ios::app);

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;


    ui->comboBoxPomoc->addItem(ui->lineEditWczytajNumer->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajNazwa_1->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajImie->text());
    ui->comboBoxPomoc->addItem(ui->lineEditWczytajNazwisko->text());
    ui->comboBoxPomoc->addItem(ui->comboBoxWczytajWojewodztwa->currentText());
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

    //plikKontrahent<<ui->

    plikKontrahent << ui->lineEditWczytajNumer->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajNazwa_1->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajImie->text().toStdString() << endl;
    plikKontrahent << ui->lineEditWczytajNazwisko->text().toStdString() << endl;
    plikKontrahent << ui->comboBoxWczytajKraj->currentText().toStdString() << endl;
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

void Kontrahent::on_actionDodaj_Kraj_triggered()
{
    cout << "Dodoaje Kraje z kontrahenta" << endl;
    KontrahentDodajKraj *kontrDodKraj = new KontrahentDodajKraj(this);
    kontrDodKraj->show();
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
    CheckFiles1 *checkFiles = new CheckFiles1(this);
    cout << "Otrzymanie highland przycisku wczytaj Miasta" << endl;
    checkFlagsVarriableMiasto = checkFiles->checkFlagsMiasto(checkFlagsVarriableMiasto);
    if (checkFlagsVarriableMiasto != 0) {
        cout << "textHighlighted" << endl;
        QStringList listaMiast = QStringList();

        ui->comboBoxWczytajMiasta->clear();
        wczytajMiasta();
        int ostatniindex = ui->comboBoxWczytajMiasta->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaMiast.push_back(ui->comboBoxWczytajMiasta->itemText(iZmienna).toUtf8());
        }
        sort(listaMiast.begin(), listaMiast.end());
        ui->comboBoxWczytajMiasta->clear();
        for (int kZmienna = 0; kZmienna <= listaMiast.count() - 1; kZmienna++) {
            ui->comboBoxWczytajMiasta->addItem(listaMiast.at(kZmienna));
        }
    }
    checkFlags.open(file10.toStdString(), ios::out | ios::trunc);
    checkFlags << "0" << endl;
    checkFlags.close();
}

//Info do Gita
//void Kontrahent::on_comboBoxWczytajMiasta_activated(const QString) //(const QString &arg1)
//{
//    cout << "Aktywacja przycisku wczytaj Miasta" << endl;
//}

//void Kontrahent::on_comboBoxWczytajMiasta_textHighlighted(const QString) {}

void Kontrahent::on_comboBoxWczytajWojewodztwa_highlighted(const QString) //const QString &arg1
{
    CheckFiles1 *checkFiles = new CheckFiles1(this);
    cout << " Otrzymanie highland przycisku wczytaj wojewdóztwo" << endl;
    checkFlagsVarriableWojewodztwo = checkFiles->checkFlagsWojewodztwa(
        checkFlagsVarriableWojewodztwo);
    if (checkFlagsVarriableWojewodztwo != 0) {
        cout << "Higladned w Przycisk wczyta Wojewodztwa" << endl;
        QStringList listaWojewodztw = QStringList();

        ui->comboBoxWczytajWojewodztwa->clear();
        wczytajWojewodztwa();
        int ostatniindex = ui->comboBoxWczytajWojewodztwa->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaWojewodztw.push_back(ui->comboBoxWczytajWojewodztwa->itemText(iZmienna).toUtf8());
        }
        sort(listaWojewodztw.begin(), listaWojewodztw.end());
        ui->comboBoxWczytajWojewodztwa->clear();
        for (int kZmienna = 0; kZmienna <= listaWojewodztw.count() - 1; kZmienna++) {
            ui->comboBoxWczytajWojewodztwa->addItem(listaWojewodztw.at(kZmienna));
        }
    }
    checkFlags.open(file12.toStdString(), ios::out | ios::trunc);
    checkFlags << "0" << endl;
    checkFlags.close();
}

void Kontrahent::on_comboBoxWczytajKraj_highlighted(const QString) //const QString &arg1
{
    CheckFiles1 *checkFiles = new CheckFiles1(this);
    cout << " Otrzymanie highland przycisku wczytaj wojewdóztwo" << endl;
    checkFlagsVarriableKraj = checkFiles->checkFlagsKraj(checkFlagsVarriableKraj);
    if (checkFlagsVarriableKraj != 0) {
        cout << "Higladned w Przycisk wczyta Kraj" << endl;
        QStringList listaKraj = QStringList();

        ui->comboBoxWczytajKraj->clear();
        wczytajKraj();
        int ostatniindex = ui->comboBoxWczytajKraj->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaKraj.push_back(ui->comboBoxWczytajKraj->itemText(iZmienna).toUtf8());
        }
        sort(listaKraj.begin(), listaKraj.end());
        ui->comboBoxWczytajKraj->clear();
        for (int kZmienna = 0; kZmienna <= listaKraj.count() - 1; kZmienna++) {
            ui->comboBoxWczytajKraj->addItem(listaKraj.at(kZmienna));
        }
    }
    checkFlags.open(file11.toStdString(), ios::out | ios::trunc);
    checkFlags << "0" << endl;
    checkFlags.close();
}

void Kontrahent::on_comboBoxWczytajKraj_activated(const QString) {}
