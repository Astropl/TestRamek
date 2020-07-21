#ifndef TIMEDATE_H
#define TIMEDATE_H
#include <string>
#include <cstring>
#include <QObject>


//int minuta;
class TimeDate : public QObject
{
    Q_OBJECT
public:
    explicit TimeDate(QObject *parent = nullptr);


public slots:
     void init();
//     QString zmianaLabela(int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia, QString qStrMin, QString qStrGodz,QString qStrSek,QString qStrDzien,QString qStrMiesiac, QString stringDzienTygodnia);
signals:

//    QString pair(int godzina, int  minuta,int   sekunda, int  dzien, int  miesiac, int rok, int dzienTygodnia, QString qStrMin, QString qStrGodz,QString qStrSek, QString qStrDzien, QString qStrMiesiac, QString stringDzienTygodnia);


    QString changeStringsMin (int minuta);
    QString changeStringsSek (int sekunda);
    QString changeStringsGodz (int godz);
    QString changeStringsDzien(int dzien);
    QString changeStringsMiesiac (int miesiac);
    QString changeStringsDzienTygodnia (int dzienTygodnia);
};

#endif // TIMEDATE_H
