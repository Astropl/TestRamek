#include "kontrahent.h"
#include "ui_kontrahent.h"
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
    cout << godzinaKontrahent << endl;
    cout << minutaKontrahent << endl;
    cout << sekundaKontrahent << endl;
    cout << dzienKontrahent << endl;
    cout << miesiacKontrahent << endl;
    cout << rokKontrahent << endl;
    cout << dzienTygodniaKontrahent << endl;
    zmianaLabela(godzinaKontrahent, minutaKontrahent, sekundaKontrahent, dzienKontrahent, miesiacKontrahent, rokKontrahent, dzienTygodniaKontrahent);
}
int Kontrahent::zmianaLabela(
    int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia)
{
    // Dodoać zera do sekund gdy mniej niz 10

    if( sekunda<10)
    {
        ui->labelZegara->setText(QString::number(godzina) + ":" + QString::number(minuta) + ":0" + QString::number(sekunda));
    }
    else{
        ui->labelZegara->setText(QString::number(godzina) + ":" + QString::number(minuta) + ":" + QString::number(sekunda));
    }


    ui->labelDaty->setText(QString::number(rok) + "." + QString::number(miesiac) + "."
                           + QString::number(dzien));
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
