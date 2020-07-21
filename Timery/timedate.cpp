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

QString TimeDate::changeStringsMin(int minuta1)
{
    cout << "Jestem w zegrach od pierwszego timedata. changeStrings" << endl;

    QString qStrMin1 = QString::number(minuta1);
    if (minuta1 < 10) {
        qStrMin1 = "0" + QString::number(minuta1);
    }
    return qStrMin1;
}
QString TimeDate::changeStringsSek(int sekunda1)
{
    QString qStrSek1 = QString::number(sekunda1);
    if (sekunda1 < 10) {
        qStrSek1 = "0" + QString::number(sekunda1);
    }
    return qStrSek1;
}
QString TimeDate::changeStringsGodz(int godzina1)
{
    QString qStrGodz1 = QString::number(godzina1);
    if (godzina1 < 10) {
        qStrGodz1 = "0" + QString::number(godzina1);
    }
    return qStrGodz1;
}
QString TimeDate::changeStringsDzien(int dzien1)
{
    QString qStrDzien1 = QString::number(dzien1);
    if (dzien1 < 10) {
        qStrDzien1 = "0" + QString::number(dzien1);
    }
    return qStrDzien1;
}
QString TimeDate::changeStringsMiesiac(int miesiac1)
{
    QString qStrMiesiac1 = QString::number(miesiac1);

    if (miesiac1 < 10) {
        qStrMiesiac1 = "0" + QString::number(miesiac1);
    }
    return qStrMiesiac1;
}
QString TimeDate::changeStringsDzienTygodnia(int dzienTygodnia1)
{QString stringDzienTygodnia1;
    switch (dzienTygodnia1) {
    case 1:
         stringDzienTygodnia1 = "Niedziela";
        break;
    case 2:
        stringDzienTygodnia1 = "Poniedziałek";
        break;
    case 3:
        stringDzienTygodnia1 = "Wtorek";
        break;
    case 4:
        stringDzienTygodnia1 = "Środa";
        break;
    case 5:
        stringDzienTygodnia1 = "Czwartek";
        break;
    case 6:
        stringDzienTygodnia1 = "Piątek";
        break;
    case 7:
        stringDzienTygodnia1 = "Sobota";
        break;
    }
    return stringDzienTygodnia1;
}


