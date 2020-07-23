#include "pierwsza.h"
#include "QApplication"
#include "Timery/timedate.h"
//#include "time.h"
#include "ui_pierwsza.h"
#include <Info/info.h>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QTimer>

using namespace std;

//int labelGodzinaPierwsza;
//int labelDataPierwsza;
//int wynikPierwsza;

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

Pierwsza::~Pierwsza()
{
    delete ui;
}

void Pierwsza::on_pushButton_clicked()
{timer->stop();
    destroy();
}

void Pierwsza::DataiCzas()
{
    cout << "Wszedłem do daty i czsu" << endl;
}
//Info do Gita