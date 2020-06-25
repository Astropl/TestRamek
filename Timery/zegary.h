#ifndef ZEGARY_H
#define ZEGARY_H

#include <QObject>
#include <QTimer>
class Zegary : public QObject
{
    Q_OBJECT
public:
    explicit Zegary(QObject *parent = nullptr);


public slots:
     int myfunctiontimer();
     int zmianaLabela(int sekunda);
signals:
    void textChanged(QString);

    void intZegary();
    void uruchom();
//    void someFunctionThatChangesText (const QString& newtext)
//    {
//        emit textChanged(newtext);
//    }
private:

    QTimer *timer;
};

#endif // ZEGARY_H
