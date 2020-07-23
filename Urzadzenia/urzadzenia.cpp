#include "urzadzenia.h"
#include "mainwindow.h"
#include "time.h"
#include "ui_urzadzenia.h"
#include "urzadzeniadodajmodel.h"
#include "urzadzeniadodajnrseryjny.h"
#include "urzadzeniadodajproducenta.h"
#include "Timery/timedate.h"
#include <Info/info.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QTimer>

using namespace std;

string stringLabela4 = ("Producent: , Model: , Nr. Seryjny: ");
QString zaznaczono;
fstream plikUrzadzenia;

//time_t czasUrzadzenia;
//tm timeinfo;
//int labelGodzina;
//int labelData;
//int wynik;
//int godzinaUrzadzenia, minutaUrzadzenia, sekundaUrzadzenia, dzienUrzadzenia, miesiacUrzadzenia, rokUrzadzenia;
//int dzienTygodniaUrzadzenia;
//string stringDzienTygodniaUrzadzenia;
//string zmiennas;

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
    plikUrzadzenia.open("C:/Defaults/Pliki/ZapisModel.txt", ios::in);
    if (plikUrzadzenia.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikUrzadzenia, linia)) {
        ui->comboBox_2->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }

    plikUrzadzenia.close();
    // wczytuj pliki z producenta
    plikUrzadzenia.open("C:/Defaults/Pliki/ZapisProducenta.txt", ios::in);
    if (plikUrzadzenia.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia1;
    int nr_lini1 = 1;
    while (getline(plikUrzadzenia, linia1)) {
        ui->comboBox->addItem(linia1.c_str());
        cout << linia1.c_str() << endl;
        nr_lini1++;
    }
    plikUrzadzenia.close();
    //wczytaj numery seryjne z pliku
    plikUrzadzenia.open("C:/Defaults/Pliki/ZapisNrSeryjny.txt", ios::in);
    if (plikUrzadzenia.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia2;
    int nr_lini2 = 1;
    while (getline(plikUrzadzenia, linia2)) {
        ui->comboBox_3->addItem(linia2.c_str());
        cout << linia2.c_str() << endl;
        nr_lini2++;
    }
    plikUrzadzenia.close();

    countriesListModel = new QStringListModel(this);

    ui->countriesList->setModel(countriesListModel);
    int row = countriesListModel->rowCount(); // pobieram liczbę wierszy

    countriesListModel->insertRow(row);                    // wstawiam dodatkowy wiersz na końcu
    QModelIndex index = countriesListModel->index(row, 0); // pobieram obiekt wstawionego indeksu
    countriesListModel->setData(index, QVariant("*"));
}
void Urzadzenia::myfunctiontimer()
{time_t czas;
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
//    time(&czasUrzadzenia);
//    timeinfo = *localtime(&czasUrzadzenia);
//    godzinaUrzadzenia = timeinfo.tm_hour;
//    minutaUrzadzenia = timeinfo.tm_min;
//    sekundaUrzadzenia = timeinfo.tm_sec;
//    dzienUrzadzenia = timeinfo.tm_mday;
//    miesiacUrzadzenia = timeinfo.tm_mon;
//    rokUrzadzenia = timeinfo.tm_year;
//    dzienTygodniaUrzadzenia = timeinfo.tm_wday;
//    miesiacUrzadzenia = miesiacUrzadzenia + 1;
//    rokUrzadzenia = rokUrzadzenia + 1900;

//    zmianaLabela(godzinaUrzadzenia, minutaUrzadzenia, sekundaUrzadzenia, dzienUrzadzenia, miesiacUrzadzenia, rokUrzadzenia, dzienTygodniaUrzadzenia);
//}
//int Urzadzenia::zmianaLabela(
//    int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia)
//{
//    // Dodoać zera do sekund gdy mniej niz 10
//    QString qStrMin = QString::number(minuta);
//    QString qStrGodz = QString::number(godzina);
//    QString qStrSek = QString::number(sekunda);
//    QString qStrDzien = QString::number( dzien);
//    QString qStrMiesiac = QString::number(miesiac);
//    if (sekunda<10)
//    {
//        qStrSek = "0"+QString::number(sekunda);
//    }
//    if (minuta <10)
//    {
//        qStrMin = "0"+QString::number(minuta);
//    }
//    if (godzina<10)
//    {
//        qStrGodz = "0"+QString::number(godzina);
//    }
//    if (miesiac <10)
//    {
//        qStrMiesiac = "0"+QString::number(miesiac);
//    }
//    if (dzien <10)
//    {
//        qStrDzien = "0"+QString::number(dzien);
//    }


//    ui->labelZegara->setText(qStrGodz + ":" + qStrMin + ":" + qStrSek);
//    ui->labelDaty->setText(QString::number(rok) + "." + qStrMiesiac + "."
//                           + qStrDzien);
//    switch (dzienTygodnia) {
//    case 1:
//        stringDzienTygodniaUrzadzenia = "Poniedziałek";
//        break;
//    case 2:
//        stringDzienTygodniaUrzadzenia = "Wtorek";
//        break;
//    case 3:
//        stringDzienTygodniaUrzadzenia = "Środa";
//        break;
//    case 4:
//        stringDzienTygodniaUrzadzenia = "Czwartek";
//        break;
//    case 5:
//        stringDzienTygodniaUrzadzenia = "Piątek";
//        break;
//    case 6:
//        stringDzienTygodniaUrzadzenia = "Sobota";
//        break;
//    case 0:
//        stringDzienTygodniaUrzadzenia = "Niedziela";
//        break;
//    }
//    ui->labelDzien->setText((stringDzienTygodniaUrzadzenia).c_str());
//    return 1;
//}
Urzadzenia::~Urzadzenia()
{
    delete ui;
}

void Urzadzenia::on_BtnUrzaZapisz_clicked()
{
    cout << "Zapisz" << endl;
}

void Urzadzenia::on_BtnUrzaZamknij_clicked()
{timer->stop();
    destroy();
}

void Urzadzenia::on_countriesList_clicked(const QModelIndex &index)
{
    int rowCount = countriesListModel->rowCount();
    countriesListModel->insertRow(rowCount);
    countriesListModel->setData(index, QVariant("Cos innego")); // i ustawiam tekst na "*"

    ui->label_4->setText(zaznaczono + " " + ui->comboBox->currentText());
}

void Urzadzenia::on_comboBox_textActivated(const QString )
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText()
                         + ", Model: " + ui->comboBox_2->currentText()
                         + ", NumerSeryjny: " + ui->comboBox_3->currentText());
}

void Urzadzenia::on_comboBox_2_textActivated(const QString )
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText()
                         + ", Model: " + ui->comboBox_2->currentText()
                         + ", NumerSeryjny: " + ui->comboBox_3->currentText());
}

void Urzadzenia::on_comboBox_3_textActivated(const QString )
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

void Urzadzenia::on_actionInformacja_triggered()
{
    Info *info= new Info(this);
    info->show();
}
//Info do Gita