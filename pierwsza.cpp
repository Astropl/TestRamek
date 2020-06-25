#include "pierwsza.h"
//#include "Timery/zegary.h"
#include "time.h"
#include "ui_pierwsza.h"
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <QString>
#include "QApplication"
#include <QTimer>

using namespace std;
time_t czas;
tm timeinfo;

int labelGodzina;
int labelData;
int wynik;
int godzina, minuta, sekunda, dzien, miesiac, rok;
int dzienTygodnia;
string stringDzienTygodnia;
string zmiennas;

Pierwsza::Pierwsza(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pierwsza)
{
    ui->setupUi(this);
    ui->labelZegara->setText(" cos tam");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);

    //===================
    cout << "zmienamaiay zegar" << endl;

    cout << wynik << endl;
    //labelZegara labelDaty

}
void Pierwsza::myfunctiontimer()
{
    cout << "Jestem w myfunction" << endl;
    time(&czas);
    timeinfo = *localtime(&czas);

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
    cout<< dzienTygodnia<<endl;

    //pier->zmianaLabela(sekunda);
    //return ( sekunda);
    zmianaLabela(godzina, minuta, sekunda, dzien, miesiac, rok, dzienTygodnia);
}

int Pierwsza::zmianaLabela(int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia)

{
    cout << "wzlasł" << endl;
    //labelGodzina = QString(godzina) + ":" + QString(minuta) + ":" + QString(sekunda);


    ui->labelZegara->setText(QString::number(godzina) + ":" + QString::number(minuta) + ":" + QString::number(sekunda));

    ui->labelDaty->setText(QString::number(rok) + "." + QString::number(miesiac) + "." + QString::number(dzien));
    switch (dzienTygodnia)
    {
    case 1:
        stringDzienTygodnia="Poniedziałek";
        break;
    case 2:
        stringDzienTygodnia="Wtorek";
        break;
    case 3:
        stringDzienTygodnia="Środa";
        break;
    case 4:
        stringDzienTygodnia="Czwartek";
        break;
    case 5:
        stringDzienTygodnia="Piątek";
        break;
    case 6:
        stringDzienTygodnia="Sobota";
        break;
    case 7:
        stringDzienTygodnia="Niedziela";
        break;

    }


    ui->labelDzien->setText((stringDzienTygodnia).c_str());

    //return sekunda ;
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
