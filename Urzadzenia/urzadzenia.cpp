#include "urzadzenia.h"
#include "mainwindow.h"
#include "time.h"
#include "ui_urzadzenia.h"
#include "urzadzeniadodajmodel.h"
#include "urzadzeniadodajnrseryjny.h"
#include "urzadzeniadodajproducenta.h"
#include "Ustawienia/ustawienia.h"
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
int iloscUrzadzen =0;
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
    ui->lineEditNumber->setText(QString::number(iloscUrzadzen));

    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================

    howMuchDevice();

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
    //countriesListModel->setData(index, QVariant("*"));
}


void Urzadzenia::howMuchDevice()
{
    // TODO: okreslić ile znajduje sie zapisanych urzadzen juz.

    plikUrzadzenia.open("C:/Defaults/Pliki/Urzadzenie.txt", ios::in);
    if (plikUrzadzenia.good() ==false)
    {
        cout<<"Plik nie istnieje";

    }
    string linia;

    int nr_lini = 1;
    while (getline(plikUrzadzenia, linia))
    {
        iloscUrzadzen ++;
        cout << linia.c_str()<<endl;
        nr_lini++;
    }
    cout<<"ilosc Urzadzen wczytanych stringów: "<< iloscUrzadzen<<endl;
    iloscUrzadzen = iloscUrzadzen /4;
     cout<<"ilosc Urzadzen po 4: "<< iloscUrzadzen<<endl;
    ui->LblNumberAnaliz->setText(QString::number(iloscUrzadzen));
    plikUrzadzenia.close();
    iloscUrzadzen ++;
     cout<<"ilosc Urzadzen z nastepnym: "<< iloscUrzadzen<<endl;
     ui->lineEditNumber->setText(QString::number(iloscUrzadzen));


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


Urzadzenia::~Urzadzenia()
{
    delete ui;
}

void Urzadzenia::on_BtnUrzaZapisz_clicked()
{
    cout << "Zapisz" << endl;

    plikUrzadzenia.open("C:/Defaults/Pliki/Urzadzenie.txt",ios::out | ios::app);
    //TODO: Plik urzadzenia




    for (int i=0;i<=ui->comboBox_4->count()-1;i++) {
        plikUrzadzenia<<ui->comboBox_4->itemText(i).toStdString()<<endl;


    }


    plikUrzadzenia.close();
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
void Urzadzenia::on_pushButton_clicked()
{
    // Dodaj do comboBoxa
    ui->comboBox_4->addItem(ui->lineEditNumber->text());
    ui->comboBox_4->addItem(ui->comboBox->currentText());
    ui->comboBox_4->addItem(ui->comboBox_2->currentText());
    ui->comboBox_4->addItem(ui->comboBox_3->currentText());
}
void Urzadzenia::on_actionOpcje_triggered()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}
