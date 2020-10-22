#ifndef TIMEDATE_H
#define TIMEDATE_H
#include <cstring>
#include <string>
#include <QObject>

//int minuta;
class TimeDate : public QObject
{
    Q_OBJECT
public:
    explicit TimeDate(QObject *parent = nullptr);

public slots:
    void init();

signals:
    QString changeStringsMin(int minuta);
    QString changeStringsSek(int sekunda);
    QString changeStringsGodz(int godz);
    QString changeStringsDzien(int dzien);
    QString changeStringsMiesiac(int miesiac);
    QString changeStringsDzienTygodnia(int dzienTygodnia);
};

#endif // TIMEDATE_H
       //Info do Gita