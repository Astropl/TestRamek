#include "timedate.h"
#include "pierwsza.h"
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//int minuta;

TimeDate::TimeDate(QObject *parent)
    : QObject(parent)
{}
void TimeDate::init()
{

}

//Wyodrebnię QStringi z minutami i godzinami i resztą

QString TimeDate::changeStringsMin(int minuta10)
{
    cout << "Jestem w zegrach od pierwszego timedata. changeStrings" << endl;

    QString qStrMin10 = QString::number(minuta10);
    if (minuta10 < 10) {
        qStrMin10 = "0" + QString::number(minuta10);
    }
    return qStrMin10;
}
QString TimeDate::changeStringsSek(int sekunda10)
{
    QString qStrSek10 = QString::number(sekunda10);
    if (sekunda10 < 10) {
        qStrSek10 = "0" + QString::number(sekunda10);
    }
    return qStrSek10;
}
QString TimeDate::changeStringsGodz(int godzina10)
{
    QString qStrGodz10 = QString::number(godzina10);
    if (godzina10 < 10) {
        qStrGodz10 = "0" + QString::number(godzina10);
    }
    return qStrGodz10;
}
QString TimeDate::changeStringsDzien(int dzien10)
{
    QString qStrDzien10 = QString::number(dzien10);
    if (dzien10 < 10) {
        qStrDzien10 = "0" + QString::number(dzien10);
    }
    return qStrDzien10;
}
QString TimeDate::changeStringsMiesiac(int miesiac10)
{
    QString qStrMiesiac10 = QString::number(miesiac10);

    if (miesiac10 < 10) {
        qStrMiesiac10 = "0" + QString::number(miesiac10);
    }
    return qStrMiesiac10;
}
QString TimeDate::changeStringsDzienTygodnia(int dzienTygodnia10)
{QString stringDzienTygodnia10;
    switch (dzienTygodnia10) {
    case 1:
         stringDzienTygodnia10 = "Niedziela";
        break;
    case 2:
        stringDzienTygodnia10 = "Poniedziałek";
        break;
    case 3:
        stringDzienTygodnia10 = "Wtorek";
        break;
    case 4:
        stringDzienTygodnia10 = "Środa";
        break;
    case 5:
        stringDzienTygodnia10 = "Czwartek";
        break;
    case 6:
        stringDzienTygodnia10 = "Piątek";
        break;
    case 7:
        stringDzienTygodnia10 = "Sobota";
        break;
    }
    return stringDzienTygodnia10;
}


