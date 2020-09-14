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

QString TimeDate::changeStringsMin(int minuta3)
{


    QString qStrMin3 = QString::number(minuta3);
    if (minuta3 < 10) {
        qStrMin3 = "0" + QString::number(minuta3);
    }
    return qStrMin3;
}
QString TimeDate::changeStringsSek(int sekunda3)
{
    QString qStrSek3 = QString::number(sekunda3);
    if (sekunda3 < 10) {
        qStrSek3 = "0" + QString::number(sekunda3);
    }
    return qStrSek3;
}
QString TimeDate::changeStringsGodz(int godzina3)
{
    QString qStrGodz3 = QString::number(godzina3);
    if (godzina3 < 10) {
        qStrGodz3 = "0" + QString::number(godzina3);
    }
    return qStrGodz3;
}
QString TimeDate::changeStringsDzien(int dzien3)
{
    QString qStrDzien3 = QString::number(dzien3);
    if (dzien3 < 10) {
        qStrDzien3 = "0" + QString::number(dzien3);
    }
    return qStrDzien3;
}
QString TimeDate::changeStringsMiesiac(int miesiac3)
{
    QString qStrMiesiac3 = QString::number(miesiac3);

    if (miesiac3 < 10) {
        qStrMiesiac3 = "0" + QString::number(miesiac3);
    }
    return qStrMiesiac3;
}
QString TimeDate::changeStringsDzienTygodnia(int dzienTygodnia3)
{QString stringDzienTygodnia3;
    switch (dzienTygodnia3) {
    case 1:
         stringDzienTygodnia3 = "Niedziela";
        break;
    case 2:
        stringDzienTygodnia3 = "Poniedziałek";
        break;
    case 3:
        stringDzienTygodnia3 = "Wtorek";
        break;
    case 4:
        stringDzienTygodnia3 = "Środa";
        break;
    case 5:
        stringDzienTygodnia3 = "Czwartek";
        break;
    case 6:
        stringDzienTygodnia3 = "Piątek";
        break;
    case 7:
        stringDzienTygodnia3 = "Sobota";
        break;
    }
    return stringDzienTygodnia3;
}

//Info do Gita
