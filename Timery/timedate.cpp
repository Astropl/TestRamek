#include "timedate.h"
#include <iostream>
#include <ctime>
using namespace std;

//time_t czas;
//tm timeinfo;

int godzina, minuta, sekunda, dzien, miesiac, rok, dzienTygodnia;
string stringDzienTygodnia;
QString qStrMin, qStrGodz,qStrSek, qStrDzien, qStrMiesiac;

TimeDate::TimeDate(QObject *parent) : QObject(parent)
{

}
void TimeDate::init()
{


//    //zmianaLabela(godzina,
//                 minuta,
//                 sekunda,
//                 dzien,
//                 miesiac,
//                 rok,
//                 dzienTygodnia);



}

QString TimeDate::zmianaLabela(int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia, QString qStrMin, QString qStrGodz,QString qStrSek,QString qStrDzien,QString qStrMiesiac, QString stringDzienTygodnia)
{
    cout<<"Jestem w zegrach druga timedata"<<endl;

    cout << "Jestem w myfunction" << endl;

    // Dodoać zera do sekund gdy mniej niz 10
    qStrMin = QString::number(minuta);
    qStrGodz = QString::number(godzina);
    qStrSek = QString::number(sekunda);
    qStrDzien = QString::number(dzien);
    qStrMiesiac = QString::number(miesiac);
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

//   /*/* ui->labelZegara->setText(qStrGodz + ":" + qStrMin + ":" + qStrSek);
//    u**//i->labelDaty->setText(QString::number(rok) + "." + qStrMiesiac + "." + qStrDzien);


    switch (dzienTygodnia) {
    case 1:
        stringDzienTygodnia = "Niedziela";
        break;
    case 2:
        stringDzienTygodnia = "Poniedziałek";
        break;
    case 3:
        stringDzienTygodnia = "Wtorek";
        break;
    case 4:
        stringDzienTygodnia = "Środa";
        break;
    case 5:
        stringDzienTygodnia = "Czwartek";
        break;
    case 6:
        stringDzienTygodnia = "Piątek";
        break;
    case 7:
        stringDzienTygodnia = "Sobota";
        break;
    }
    //ui->labelDzien->setText((stringDzienTygodnia).c_str());
    QString pairConst;
    pair(godzina,  minuta,  sekunda,  dzien,  miesiac,  rok,  dzienTygodnia, qStrMin, qStrGodz,qStrSek, qStrDzien, qStrMiesiac,  stringDzienTygodnia);
    return pairConst;
}
QString TimeDate::pair(int godzina, int  minuta,int   sekunda, int  dzien, int  miesiac, int rok, int dzienTygodnia, QString qStrMin, QString qStrGodz,QString qStrSek, QString qStrDzien, QString qStrMiesiac, QString stringDzienTygodnia)
{
    QString pairConst = (godzina,  minuta,  sekunda,  dzien,  miesiac,  rok,  dzienTygodnia, qStrMin, qStrGodz,qStrSek, qStrDzien, qStrMiesiac,  stringDzienTygodnia);
    return pairConst;
}
