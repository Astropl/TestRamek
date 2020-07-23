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

QString TimeDate::changeStringsMin(int minuta2)
{
    cout << "Jestem w zegrach od pierwszego timedata. changeStrings" << endl;

    QString qStrMin2 = QString::number(minuta2);
    if (minuta2 < 10) {
        qStrMin2 = "0" + QString::number(minuta2);
    }
    return qStrMin2;
}
QString TimeDate::changeStringsSek(int sekunda2)
{
    QString qStrSek2 = QString::number(sekunda2);
    if (sekunda2 < 10) {
        qStrSek2 = "0" + QString::number(sekunda2);
    }
    return qStrSek2;
}
QString TimeDate::changeStringsGodz(int godzina2)
{
    QString qStrGodz2 = QString::number(godzina2);
    if (godzina2 < 10) {
        qStrGodz2 = "0" + QString::number(godzina2);
    }
    return qStrGodz2;
}
QString TimeDate::changeStringsDzien(int dzien2)
{
    QString qStrDzien2 = QString::number(dzien2);
    if (dzien2 < 10) {
        qStrDzien2 = "0" + QString::number(dzien2);
    }
    return qStrDzien2;
}
QString TimeDate::changeStringsMiesiac(int miesiac2)
{
    QString qStrMiesiac2 = QString::number(miesiac2);

    if (miesiac2 < 10) {
        qStrMiesiac2 = "0" + QString::number(miesiac2);
    }
    return qStrMiesiac2;
}
QString TimeDate::changeStringsDzienTygodnia(int dzienTygodnia2)
{QString stringDzienTygodnia2;
    switch (dzienTygodnia2) {
    case 1:
         stringDzienTygodnia2 = "Niedziela";
        break;
    case 2:
        stringDzienTygodnia2 = "Poniedziałek";
        break;
    case 3:
        stringDzienTygodnia2 = "Wtorek";
        break;
    case 4:
        stringDzienTygodnia2 = "Środa";
        break;
    case 5:
        stringDzienTygodnia2 = "Czwartek";
        break;
    case 6:
        stringDzienTygodnia2 = "Piątek";
        break;
    case 7:
        stringDzienTygodnia2 = "Sobota";
        break;
    }
    return stringDzienTygodnia2;
}

//Info do Gita
