#include "pierwsza.h"
//#include "Timery/zegary.h"
#include "QApplication"
#include "time.h"
#include "ui_pierwsza.h"
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QTimer>

using namespace std;
time_t czasPierwsza;
tm timeinfoPierwsza;

int labelGodzinaPierwsza;
int labelDataPierwsza;
int wynikPierwsza;
int godzinaPierwsza, minutaPierwsza, sekundaPierwsza, dzienPierwsza, miesiacPierwsza, rokPierwsza;
int dzienTygodniaPierwsza;
string stringDzienTygodniaPierwsza;
string zmiennasPierwsza;

Pierwsza::Pierwsza(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pierwsza)
{
    ui->setupUi(this);
    ui->labelZegara->setText(" cos tam");
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
}
void Pierwsza::myfunctiontimer()
{
    cout << "Jestem w myfunction" << endl;
    time(&czasPierwsza);
    timeinfoPierwsza = *localtime(&czasPierwsza);
    godzinaPierwsza = timeinfoPierwsza.tm_hour;
    minutaPierwsza = timeinfoPierwsza.tm_min;
    sekundaPierwsza = timeinfoPierwsza.tm_sec;
    dzienPierwsza = timeinfoPierwsza.tm_mday;
    miesiacPierwsza = timeinfoPierwsza.tm_mon;
    rokPierwsza = timeinfoPierwsza.tm_year;
    dzienTygodniaPierwsza = timeinfoPierwsza.tm_wday;
    miesiacPierwsza = miesiacPierwsza + 1;
    rokPierwsza = rokPierwsza + 1900;
    cout << godzinaPierwsza << endl;
    cout << minutaPierwsza << endl;
    cout << sekundaPierwsza << endl;
    cout << dzienPierwsza << endl;
    cout << miesiacPierwsza << endl;
    cout << rokPierwsza << endl;
    cout << dzienTygodniaPierwsza << endl;
    zmianaLabela(godzinaPierwsza, minutaPierwsza, sekundaPierwsza, dzienPierwsza, miesiacPierwsza, rokPierwsza, dzienTygodniaPierwsza);
}
int Pierwsza::zmianaLabela(
    int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia)
{
    ui->labelZegara->setText(QString::number(godzina) + ":" + QString::number(minuta) + ":"
                             + QString::number(sekunda));
    ui->labelDaty->setText(QString::number(rok) + "." + QString::number(miesiac) + "."
                           + QString::number(dzien));
    switch (dzienTygodnia) {
    case 1:
        stringDzienTygodniaPierwsza = "Poniedziałek";
        break;
    case 2:
        stringDzienTygodniaPierwsza = "Wtorek";
        break;
    case 3:
        stringDzienTygodniaPierwsza = "Środa";
        break;
    case 4:
        stringDzienTygodniaPierwsza = "Czwartek";
        break;
    case 5:
        stringDzienTygodniaPierwsza = "Piątek";
        break;
    case 6:
        stringDzienTygodniaPierwsza = "Sobota";
        break;
    case 7:
        stringDzienTygodniaPierwsza = "Niedziela";
        break;
    }
    ui->labelDzien->setText((stringDzienTygodniaPierwsza).c_str());
}
Pierwsza::~Pierwsza()
{
    delete ui;
}

void Pierwsza::on_pushButton_clicked()
{
    destroy();
}

void Pierwsza::DataiCzas()
{
    cout << "Wszedłem do daty i czsu" << endl;
}
