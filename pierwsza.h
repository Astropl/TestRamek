#ifndef PIERWSZA_H
#define PIERWSZA_H

#include <QMainWindow>

namespace Ui {
class Pierwsza;
}

class Pierwsza : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pierwsza(QWidget *parent = nullptr);
    ~Pierwsza();

public slots:
    void on_pushButton_clicked();
    int zmianaLabela(int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia);
    void myfunctiontimer();
    void DataiCzas();

signals:

    //void intZegary();

public:
    Ui::Pierwsza *ui;

private:
    QTimer *timer;
    // Ui::labelZegara *ui;
};

#endif // PIERWSZA_H
