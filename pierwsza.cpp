#include "pierwsza.h"
//#include "Timery/zegary.h"
#include "QApplication"
#include "time.h"
#include "ui_pierwsza.h"
#include <Info/info.h>
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

    zmianaLabela(godzinaPierwsza,
                 minutaPierwsza,
                 sekundaPierwsza,
                 dzienPierwsza,
                 miesiacPierwsza,
                 rokPierwsza,
                 dzienTygodniaPierwsza);
}
int Pierwsza::zmianaLabela(
    int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia)
{
    dzienTygodnia = dzienTygodnia + 1;
    // Dodoać zera do sekund gdy mniej niz 10
    QString qStrMin = QString::number(minuta);
    QString qStrGodz = QString::number(godzina);
    QString qStrSek = QString::number(sekunda);
    QString qStrDzien = QString::number(dzien);
    QString qStrMiesiac = QString::number(miesiac);
    if (sekunda < 10) {
        qStrSek = "0" + QString::number(sekunda);
    }
    if (minuta < 10) {
        qStrMin = "0" + QString::number(minuta);
    }
    if (godzina < 10) {
        qStrGodz = "0" + QString::number(godzina);
    }
    if (miesiac < 10) {
        qStrMiesiac = "0" + QString::number(miesiac);
    }
    if (dzien < 10) {
        qStrDzien = "0" + QString::number(dzien);
    }

    ui->labelZegara->setText(qStrGodz + ":" + qStrMin + ":" + qStrSek);
    ui->labelDaty->setText(QString::number(rok) + "." + qStrMiesiac + "." + qStrDzien);
    switch (dzienTygodnia) {
    case 1:
        stringDzienTygodniaPierwsza = "Niedziela";
        break;
    case 2:
        stringDzienTygodniaPierwsza = "Poniedziałek";
        break;
    case 3:
        stringDzienTygodniaPierwsza = "Wtorek";
        break;
    case 4:
        stringDzienTygodniaPierwsza = "Środa";
        break;
    case 5:
        stringDzienTygodniaPierwsza = "Czwartek";
        break;
    case 6:
        stringDzienTygodniaPierwsza = "Piątek";
        break;
    case 7:
        stringDzienTygodniaPierwsza = "Sobota";
        break;
    }
    ui->labelDzien->setText((stringDzienTygodniaPierwsza).c_str());
    return 0;
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
