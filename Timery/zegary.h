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

signals:
    void textChanged(QString);
    void intZegary();
    void uruchom();

private:
    QTimer *timer;
};

#endif // ZEGARY_H
       //Info do Gita