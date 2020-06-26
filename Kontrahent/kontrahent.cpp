#include "kontrahent.h"
#include "ui_kontrahent.h"
#include "kontrahentdodajmiasto.h"
#include "kontrahentdodajwojewodztwo.h"
#include <iostream>
#include "time.h"
#include <ctime>
#include <QString>
#include <QTimer>

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
    case 7:
        stringDzienTygodniaKontrahent = "Niedziela";
        break;
    }
    ui->labelDzien->setText((stringDzienTygodniaKontrahent).c_str());
}

void Kontrahent::on_pushButton_clicked()
{
    //Zapisz
    cout<<"Zapisuje"<<endl;
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
