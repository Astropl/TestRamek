#ifndef TIMEDATE_H
#define TIMEDATE_H

#include <QObject>

class TimeDate : public QObject
{
    Q_OBJECT
public:
    explicit TimeDate(QObject *parent = nullptr);


public slots:
     void init();
     QString zmianaLabela(int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia, QString qStrMin, QString qStrGodz,QString qStrSek,QString qStrDzien,QString qStrMiesiac, QString stringDzienTygodnia);
signals:

    QString pair(int godzina, int  minuta,int   sekunda, int  dzien, int  miesiac, int rok, int dzienTygodnia, QString qStrMin, QString qStrGodz,QString qStrSek, QString qStrDzien, QString qStrMiesiac, QString stringDzienTygodnia);
};

#endif // TIMEDATE_H
